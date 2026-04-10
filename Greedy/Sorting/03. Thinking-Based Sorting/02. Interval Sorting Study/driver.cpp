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
    vector<pair<int, int>> intervals;
    vector<pair<int, int>> expectedStart;
    vector<pair<int, int>> expectedEnd;
    vector<pair<int, int>> expectedLength;
};

class ResultFormatter {
public:
    static string vectorToString(const vector<pair<int, int>>& v) {
        string s = "[";
        for (int i = 0; i < (int)v.size(); i++) {
            s += "(" + to_string(v[i].first) + "," + to_string(v[i].second) + ")";
            if (i + 1 < (int)v.size()) s += ",";
        }
        return s + "]";
    }
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            // Case 1: Simple array
            { {{1, 4}, {2, 3}, {3, 5}, {6, 7}}, 
              {{1, 4}, {2, 3}, {3, 5}, {6, 7}}, 
              {{2, 3}, {1, 4}, {3, 5}, {6, 7}}, 
              {{2, 3}, {6, 7}, {3, 5}, {1, 4}} 
            },
            // Case 2: Overlapping
            { {{1, 10}, {2, 3}, {5, 8}},
              {{1, 10}, {2, 3}, {5, 8}},
              {{2, 3}, {5, 8}, {1, 10}},
              {{2, 3}, {5, 8}, {1, 10}}
            },
            // Case 3: Same start, diff end
            { {{1, 5}, {1, 2}, {1, 10}},
              {{1, 2}, {1, 5}, {1, 10}},
              {{1, 2}, {1, 5}, {1, 10}},
              {{1, 2}, {1, 5}, {1, 10}}
            },
            // Case 4: Same end, diff start
            { {{5, 10}, {2, 10}, {8, 10}},
              {{2, 10}, {5, 10}, {8, 10}},
              {{2, 10}, {5, 10}, {8, 10}},
              {{8, 10}, {5, 10}, {2, 10}}
            },
            // Case 5: Zero length (point)
            { {{5, 5}, {1, 1}, {10, 10}},
              {{1, 1}, {5, 5}, {10, 10}},
              {{1, 1}, {5, 5}, {10, 10}},
              {{1, 1}, {5, 5}, {10, 10}}
            }
        };
        
        // Add more tests to reach 15
        cases.push_back({ {{1, 2}}, {{1, 2}}, {{1, 2}}, {{1, 2}} });
        cases.push_back({ {{1, 100}, {50, 51}, {2, 3}}, {{1, 100}, {2, 3}, {50, 51}}, {{2, 3}, {50, 51}, {1, 100}}, {{2, 3}, {50, 51}, {1, 100}} });
        cases.push_back({ {{10, 20}, {10, 20}, {10, 20}}, {{10, 20}, {10, 20}, {10, 20}}, {{10, 20}, {10, 20}, {10, 20}}, {{10, 20}, {10, 20}, {10, 20}} });
        cases.push_back({ {{1, 5}, {0, 6}}, {{0, 6}, {1, 5}}, {{1, 5}, {0, 6}}, {{1, 5}, {0, 6}} });
        cases.push_back({ {{0, 0}, {0, 10}}, {{0, 0}, {0, 10}}, {{0, 0}, {0, 10}}, {{0, 0}, {0, 10}} });
        cases.push_back({ {{10, 15}, {5, 15}, {0, 15}}, {{0, 15}, {5, 15}, {10, 15}}, {{0, 15}, {5, 15}, {10, 15}}, {{10, 15}, {5, 15}, {0, 15}} });
        cases.push_back({ {{1, 2}, {3, 4}, {5, 6}}, {{1, 2}, {3, 4}, {5, 6}}, {{1, 2}, {3, 4}, {5, 6}}, {{1, 2}, {3, 4}, {5, 6}} });
        cases.push_back({ {{5, 6}, {3, 4}, {1, 2}}, {{1, 2}, {3, 4}, {5, 6}}, {{1, 2}, {3, 4}, {5, 6}}, {{1, 2}, {3, 4}, {5, 6}} });
        cases.push_back({ {{1, 10}, {2, 5}, {3, 4}}, {{1, 10}, {2, 5}, {3, 4}}, {{3, 4}, {2, 5}, {1, 10}}, {{3, 4}, {2, 5}, {1, 10}} });
        cases.push_back({ {{1, 10}, {1, 9}, {1, 8}}, {{1, 8}, {1, 9}, {1, 10}}, {{1, 8}, {1, 9}, {1, 10}}, {{1, 8}, {1, 9}, {1, 10}} });

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Interval Sorting..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            auto resStart = sol.sortByStart(tc.intervals);
            auto resEnd   = sol.sortByEnd(tc.intervals);
            auto resLen   = sol.sortByLength(tc.intervals);

            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();

            bool ok = (resStart == tc.expectedStart && resEnd == tc.expectedEnd && resLen == tc.expectedLength);

            if (ok) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::YELLOW << "Input: " << ResultFormatter::vectorToString(tc.intervals) << Color::RESET << "\n";
                if (resStart != tc.expectedStart) cout << "     " << Color::RED << "Start  - Expected: " << ResultFormatter::vectorToString(tc.expectedStart) << ", Got: " << ResultFormatter::vectorToString(resStart) << Color::RESET << "\n";
                if (resEnd != tc.expectedEnd) cout << "     " << Color::RED << "End    - Expected: " << ResultFormatter::vectorToString(tc.expectedEnd) << ", Got: " << ResultFormatter::vectorToString(resEnd) << Color::RESET << "\n";
                if (resLen != tc.expectedLength) cout << "     " << Color::RED << "Length - Expected: " << ResultFormatter::vectorToString(tc.expectedLength) << ", Got: " << ResultFormatter::vectorToString(resLen) << Color::RESET << "\n";
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
