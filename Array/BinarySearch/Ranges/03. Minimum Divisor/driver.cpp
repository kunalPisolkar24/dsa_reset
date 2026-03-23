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
    int limit;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {10, 20, 30}, 6, 10 },
            { {1, 2, 5, 9}, 6, 5 },
            { {44, 22, 33, 11, 1}, 5, 44 },
            { {21212, 10101, 12121}, 1000000, 1 },
            { {1, 1, 1, 1, 1}, 5, 1 },
            { {1000000}, 1, 1000000 },
            { {1000000}, 2, 500000 },
            { {1000000}, 1000000, 1 },
            { {2, 3, 5, 7, 11}, 11, 3 },
            { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10 },
            { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 55, 1 },
            { {100, 200, 300}, 3, 300 },
            { {100, 200, 300}, 4, 200 },
            { {100, 200, 300}, 5, 150 },
            { {100, 200, 300}, 6, 100 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Minimum Divisor..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.smallestDivisor(tc.nums, tc.limit);
            
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
