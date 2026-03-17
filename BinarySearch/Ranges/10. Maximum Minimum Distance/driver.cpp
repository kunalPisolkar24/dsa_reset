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
    vector<int> positions;
    int k;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {1, 2, 8, 4, 9}, 3, 3 },
            { {10, 2, 5, 3, 15}, 3, 5 },
            { {1, 2, 3, 4, 5}, 2, 4 },
            { {1, 2, 3, 4, 5}, 5, 1 },
            { {1, 10, 20}, 2, 19 },
            { {1, 10, 20}, 3, 9 },
            { {0, 0, 0, 0}, 2, 0 }, // wait. positions can be same? constraints say stalls are at locations. usually unique in problems but let's see. 
                                   // if same, dist = 0.
            { {1, 10, 100, 1000}, 2, 999 },
            { {1, 10, 100, 1000}, 4, 9 }, // min(9, 90, 900) = 9.
            { {10, 20, 30, 40, 50}, 3, 20 },
            { {1, 5, 10, 100}, 2, 99 },
            { {1, 5, 10, 100}, 3, 9 }, // (1, 10, 100) -> 9, 90 -> 9.
            { {1, 2, 4, 8, 16}, 3, 7 }, // (1, 8, 16) -> 7, 8 -> 7.
            { {1, 2, 4, 8, 16}, 2, 15 },
            { {0, 1000000000}, 2, 1000000000 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Maximum Minimum Distance..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.maxMinDistance(tc.positions, tc.k);
            
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
