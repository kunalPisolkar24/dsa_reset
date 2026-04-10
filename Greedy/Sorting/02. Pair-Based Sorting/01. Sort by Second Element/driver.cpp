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
    vector<pair<int, int>> arr;
    vector<pair<int, int>> expected;
};

class ResultFormatter {
public:
    static string pairToString(const pair<int, int>& p) {
        return "(" + to_string(p.first) + "," + to_string(p.second) + ")";
    }

    static string vectorToString(const vector<pair<int, int>>& v) {
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
            { {{1, 5}, {2, 3}, {4, 6}, {3, 2}}, {{3, 2}, {2, 3}, {1, 5}, {4, 6}} },
            { {{10, 1}, {5, 5}, {2, 0}}, {{2, 0}, {10, 1}, {5, 5}} },
            { {{1, 1}, {2, 1}, {0, 1}}, {{0, 1}, {1, 1}, {2, 1}} }, // same second, sort by first
            { {{5, 2}, {5, 3}, {5, 1}}, {{5, 1}, {5, 2}, {5, 3}} },
            { {{1, 10}, {2, 10}, {1, 5}, {2, 5}}, {{1, 5}, {2, 5}, {1, 10}, {2, 10}} },
            { {{100, 100}}, {{100, 100}} },
            { {{10, -5}, {20, -10}, {0, 0}}, {{20, -10}, {10, -5}, {0, 0}} },
            { {{1, 2}, {2, 1}}, {{2, 1}, {1, 2}} },
            { {{-1, -1}, {-2, -1}, {-1, -2}}, {{-1, -2}, {-2, -1}, {-1, -1}} },
            { {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}, {{0, -1}, {-1, 0}, {0, 0}, {1, 0}, {0, 1}} },
            { {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}}, {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}} },
            { {{1, 1}, {1, 1}, {1, 1}}, {{1, 1}, {1, 1}, {1, 1}} },
            { {{1000, 10}, {1, 1000}, {10, 100}}, {{1000, 10}, {10, 100}, {1, 1000}} },
            { {{2, 3}, {3, 2}, {1, 2}, {2, 1}}, {{2, 1}, {1, 2}, {3, 2}, {2, 3}} },
            { {{9, 9}, {1, 1}, {5, 5}}, {{1, 1}, {5, 5}, {9, 9}} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Sort by Second Element..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            vector<pair<int, int>> result = sol.sortBySecond(tc.arr);

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
