#include <bits/stdc++.h>
#include "solution.cpp"

using namespace std;

struct Color {
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string RESET;
    static const string BOLD;
};

const string Color::RED    = "\033[31m";
const string Color::GREEN  = "\033[32m";
const string Color::YELLOW = "\033[33m";
const string Color::RESET  = "\033[0m";
const string Color::BOLD   = "\033[1m";

struct TestCase {
    vector<pair<int, char>> arr;
    vector<pair<int, char>> expected;
};

class ResultFormatter {
public:
    static string pairToString(const pair<int, char>& p) {
        return "(" + to_string(p.first) + ",'" + p.second + "')";
    }

    static string vectorToString(const vector<pair<int, char>>& v) {
        string s = "[";
        for (int i = 0; i < (int)v.size(); i++) {
            s += pairToString(v[i]);
            if (i + 1 < (int)v.size()) s += ", ";
        }
        return s + "]";
    }
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {{1, 'A'}, {3, 'B'}, {1, 'C'}, {2, 'D'}}, {{1, 'A'}, {1, 'C'}, {2, 'D'}, {3, 'B'}} },
            { {{2, 'X'}, {1, 'Y'}, {2, 'Z'}}, {{1, 'Y'}, {2, 'X'}, {2, 'Z'}} },
            { {{5, 'P'}, {5, 'Q'}, {5, 'R'}}, {{5, 'P'}, {5, 'Q'}, {5, 'R'}} },
            { {{1, 'Z'}, {1, 'Y'}, {1, 'X'}}, {{1, 'Z'}, {1, 'Y'}, {1, 'X'}} },
            { {{10, 'A'}, {5, 'B'}, {10, 'C'}, {5, 'D'}}, {{5, 'B'}, {5, 'D'}, {10, 'A'}, {10, 'C'}} },
            { {{42, 'M'}}, {{42, 'M'}} },
            { {{1, 'A'}, {2, 'B'}, {3, 'C'}}, {{1, 'A'}, {2, 'B'}, {3, 'C'}} },
            { {{3, 'A'}, {2, 'B'}, {1, 'C'}}, {{1, 'C'}, {2, 'B'}, {3, 'A'}} },
            { {{10, 'K'}, {10, 'J'}, {10, 'I'}}, {{10, 'K'}, {10, 'J'}, {10, 'I'}} },
            { {{1, 'A'}, {10, 'B'}, {1, 'C'}, {10, 'D'}, {1, 'E'}}, {{1, 'A'}, {1, 'C'}, {1, 'E'}, {10, 'B'}, {10, 'D'}} },
            { {{0, 'S'}, {0, 'T'}}, {{0, 'S'}, {0, 'T'}} },
            { {{100, 'Z'}, {50, 'Y'}, {100, 'X'}, {50, 'W'}}, {{50, 'Y'}, {50, 'W'}, {100, 'Z'}, {100, 'X'}} },
            { {{1, '1'}, {1, '2'}, {1, '3'}}, {{1, '1'}, {1, '2'}, {1, '3'}} },
            { {{2, 'A'}, {1, 'A'}}, {{1, 'A'}, {2, 'A'}} },
            { {{10, 'Z'}, {9, 'Y'}, {10, 'X'}, {9, 'W'}, {10, 'V'}}, {{9, 'Y'}, {9, 'W'}, {10, 'Z'}, {10, 'X'}, {10, 'V'}} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Stability Observation..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            vector<pair<int, char>> result = sol.stableSortByValue(tc.arr);

            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();

            if (result == tc.expected) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::YELLOW << "Input: " << ResultFormatter::vectorToString(tc.arr) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << ResultFormatter::vectorToString(tc.expected) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: " << ResultFormatter::vectorToString(result) << Color::RESET << "\n";
            }

            if (!logs.empty()) {
                cout << Color::YELLOW << "   Logs:" << Color::RESET << "\n";
                stringstream logStream(logs);
                string line;
                while (getline(logStream, line)) cout << "     " << line << "\n";
            }
        }

        cout << "\n";
        printSummary(passedCount, totalCount);
    }

private:
    void printSummary(int passedCount, int totalCount) {
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
        if (passedCount == totalCount) {
            cout << Color::GREEN << Color::BOLD
                 << "  ALL TESTS PASSED! (" << passedCount << "/" << totalCount << ")"
                 << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD
                 << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)"
                 << Color::RESET << "\n";
        }
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
    }
};

int main() {
    TestRunner runner;
    runner.run();
    return 0;
}
