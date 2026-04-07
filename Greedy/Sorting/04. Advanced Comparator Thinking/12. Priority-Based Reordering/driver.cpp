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
    vector<int> arr;
    vector<int> priority;
    vector<int> expected;
};

class ResultFormatter {
public:
    static string vectorToString(const vector<int>& v) {
        string s = "[";
        for (int i = 0; i < (int)v.size(); i++) {
            s += to_string(v[i]);
            if (i + 1 < (int)v.size()) s += ",";
        }
        return s + "]";
    }
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {7, 2, 5, 3, 9, 3}, {5, 3, 7}, {5, 3, 3, 7, 2, 9} },
            { {1, 4, 2, 3}, {4, 1}, {4, 1, 2, 3} },
            { {10, 20, 30}, {}, {10, 20, 30} },
            { {1, 2, 3}, {1, 2, 3}, {1, 2, 3} },
            { {3, 2, 1}, {1, 2, 3}, {1, 2, 3} },
            { {5, 5, 5, 1, 1}, {1}, {1, 1, 5, 5, 5} },
            { {10, 5, 10, 5}, {5, 10}, {5, 5, 10, 10} },
            { {1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, {5, 4, 3, 2, 1} },
            { {7, 8, 9}, {1, 2, 3}, {7, 8, 9} }, // priority not in arr
            { {1, 1, 1}, {1}, {1, 1, 1} },
            { {100, -100, 0}, {0, 100, -100}, {0, 100, -100} },
            { {2, 2, 1, 1}, {1, 2}, {1, 1, 2, 2} },
            { {5, 2, 8, 1}, {8, 1, 5, 2}, {8, 1, 5, 2} },
            { {9, 7, 5, 3, 1}, {3, 7}, {3, 7, 1, 5, 9} },
            { {4, 3, 2, 1}, {2, 4}, {2, 4, 1, 3} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Priority-Based Reordering..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            vector<int> result = sol.priorityReorder(tc.arr, tc.priority);

            if (result == tc.expected) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::YELLOW << "Input: arr=" << ResultFormatter::vectorToString(tc.arr) 
                     << ", priority=" << ResultFormatter::vectorToString(tc.priority) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << ResultFormatter::vectorToString(tc.expected) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got:      " << ResultFormatter::vectorToString(result) << Color::RESET << "\n";
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
