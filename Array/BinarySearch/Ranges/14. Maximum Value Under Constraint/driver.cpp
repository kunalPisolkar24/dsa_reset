#include <bits/stdc++.h>
#include "Solution.cpp"

using namespace std;

struct Color {
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string RESET;
    static const string BOLD;
};

const string Color::RED = "\033[31m";
const string Color::GREEN = "\033[32m";
const string Color::YELLOW = "\033[33m";
const string Color::RESET = "\033[0m";
const string Color::BOLD = "\033[1m";

struct TestCase {
    vector<int> nums;
    long long budget;
    long long expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {1, 4, 9}, 10, 5 },
            { {10, 20, 30}, 25, 8 },
            { {1, 1, 1}, 2, 0 },
            { {100, 100, 100}, 150, 50 },
            { {1, 2, 3, 4, 5}, 10, 2 },
            { {1, 2, 3, 4, 5}, 8, 1 },
            { {10, 20, 30, 40, 50}, 100, 23 },
            { {2, 2, 2, 2, 2}, 7, 1 },
            { {1, 1, 1, 1, 1}, 4, 0 },
            { {1000000000}, 500000000, 500000000 },
            { {10, 10, 10}, 5, 1 },
            { {10, 10, 10}, 25, 8 },
            { {5, 5, 5}, 10, 3 },
            { {5, 5, 5}, 14, 4 },
            { {1, 10, 100, 1000}, 50, 19 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Maximum Value Under Constraint..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            long long result = sol.maxValueUnderConstraint(tc.nums, tc.budget);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << tc.expected << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: " << result << Color::RESET << "\n";
            }
            
            if (!logs.empty()) {
                cout << Color::YELLOW << "   Logs:" << Color::RESET << "\n";
                stringstream logStream(logs);
                string line;
                while (getline(logStream, line)) {
                    cout << "     " << line << "\n";
                }
            }
        }
        
        cout << "\n";
        printSummary(passedCount, totalCount);
    }

private:
    void printSummary(int passedCount, int totalCount) {
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
        if (passedCount == totalCount) {
            cout << Color::GREEN << Color::BOLD << "  ALL TESTS PASSED! (" << passedCount << "/" << totalCount << ")" << Color::RESET << "\n";
            cout << Color::GREEN << "  (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧" << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)" << Color::RESET << "\n";
            cout << Color::RED << "  (╯°□°）╯︵ ┻━┻" << Color::RESET << "\n";
        }
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
    }
};

int main() {
    TestRunner runner;
    runner.run();
    return 0;
}
