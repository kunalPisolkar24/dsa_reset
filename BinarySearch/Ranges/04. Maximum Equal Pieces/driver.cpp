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
    int k;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {8, 5, 8}, 5, 4 },
            { {1, 1, 1}, 4, 0 },
            { {10, 20, 30}, 6, 10 },
            { {10, 20, 30}, 60, 1 },
            { {10, 20, 30}, 61, 0 },
            { {10, 10, 10}, 3, 10 },
            { {1, 2, 3, 4, 5}, 5, 2 },
            { {1000000000}, 1, 1000000000 },
            { {1000000000}, 2, 500000000 },
            { {5, 5, 5, 5}, 8, 2 },
            { {7, 9, 11}, 3, 7 },
            { {10, 10}, 1, 10 },
            { {1, 1, 1, 1, 1}, 5, 1 },
            { {12, 12, 12}, 4, 6 }, // 12/6=2, total 6. 12/7=1, total 3. 6 is max L.
                                   // 12/9=1, total 3. 12/8=1, total 3. 
                                   // Actually 12/9=1, so total 3 pieces.
                                   // For 4 pieces: 12/6=2, so total 6 pieces. 
                                   // If mid=7, 12/7=1, total 3. 
                                   // Max L is 6 for k=4 and nums={12,12,12}.
            { {20, 30, 40}, 5, 15 } // 20/15=1, 30/15=2, 40/15=2. Total 5. 16: 1+1+2=4.
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Maximum Equal Pieces..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.maxPieceLength(tc.nums, tc.k);
            
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
