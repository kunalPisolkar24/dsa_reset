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
            { {{10, 2}, {5, 1}, {8, 4}, {6, 3}}, {{10, 2}, {5, 1}, {8, 4}, {6, 3}} },
            { {{1, 3}, {2, 5}, {3, 7}}, {{3, 7}, {2, 5}, {1, 3}} },
            { {{10, 5}, {20, 10}}, {{20, 10}, {10, 5}} },
            { {{10, 1}, {1, 10}}, {{10, 1}, {1, 10}} },
            { {{1, 1}, {2, 2}, {3, 3}}, {{3, 3}, {2, 2}, {1, 1}} }, // all ratio 1
            { {{100, 1}, {100, 2}, {100, 3}}, {{100, 1}, {100, 2}, {100, 3}} },
            { {{1, 100}, {2, 100}, {3, 100}}, {{3, 100}, {2, 100}, {1, 100}} },
            { {{500, 500}, {100, 100}, {1000, 1000}}, {{1000, 1000}, {500, 500}, {100, 100}} },
            { {{7, 3}, {5, 2}}, {{5, 2}, {7, 3}} }, // 2.5 vs 2.33
            { {{10, 3}, {7, 2}, {4, 1}}, {{4, 1}, {7, 2}, {10, 3}} }, // 4, 3.5, 3.33
            { {{1, 1}}, {{1, 1}} },
            { {{1000000000, 1}, {1, 1000000000}}, {{1000000000, 1}, {1, 1000000000}} },
            { {{100, 10}, {10, 1}}, {{100, 10}, {10, 1}} },
            { {{3, 5}, {3, 4}, {3, 3}}, {{3, 3}, {3, 4}, {3, 5}} },
            { {{100, 1}, {100, 100}, {100, 10}}, {{100, 1}, {100, 10}, {100, 100}} }
        };
        
        // Correcting Case 12 Power
        cases[11] = { {{1000000000, 1}, {1, 1000000000}}, {{1000000000, 1}, {1, 1000000000}} };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Sort by Ratio..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            vector<pair<int, int>> result = sol.sortByRatio(tc.arr);

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
