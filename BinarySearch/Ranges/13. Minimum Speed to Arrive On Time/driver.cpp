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
    vector<int> dist;
    double hour;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {1, 3, 2}, 6.0, 1 },
            { {1, 3, 2}, 2.7, 3 },
            { {1, 3, 2}, 1.9, -1 },
            { {1, 1, 100000}, 2.01, 10000000 },
            { {1, 1}, 1.0, -1 },
            { {1, 1}, 2.0, 1 },
            { {1, 1}, 1.5, 2 }, // ceil(1/2) + 1/2 = 1 + 0.5 = 1.5. Correct.
            { {5, 5, 5}, 3.0, 5 },
            { {5, 5, 5}, 2.5, 10 }, // 1 + 1 + 0.5 = 2.5
            { {10}, 1.0, 10 },
            { {10}, 0.5, 20 },
            { {10}, 0.1, 100 },
            { {1, 2, 3}, 100.0, 1 },
            { {1, 1, 1}, 2.1, 10 }, // 1 + 1 + 0.1 = 2.1. Correct. 
            { {100000}, 1.0, 100000 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Minimum Speed to Arrive On Time..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.minSpeedOnTime(tc.dist, tc.hour);
            
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
