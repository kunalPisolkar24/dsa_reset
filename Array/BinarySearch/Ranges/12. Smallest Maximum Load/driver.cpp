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
    vector<int> tasks;
    int k;
    long long expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {1, 2, 3, 4, 5}, 3, 6 },
            { {10, 20, 30}, 2, 30 },
            { {1, 1, 1, 1, 1}, 5, 1 },
            { {1, 1, 1, 1, 1}, 1, 5 },
            { {10, 20, 30, 40}, 2, 60 },
            { {5, 5, 5, 5, 5}, 3, 10 },
            { {1, 2, 3}, 2, 3 },
            { {100}, 1, 100 },
            { {1, 10, 100, 1000}, 2, 1000 },
            { {1, 1, 10, 10, 1}, 2, 12 },
            { {1, 2, 4, 8, 16}, 3, 16 },
            { {7, 2, 5, 10, 8}, 2, 18 },
            { {3, 1, 4, 1, 5}, 3, 5 },
            { {10, 10, 10}, 3, 10 },
            { {10, 20, 30}, 3, 30 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Smallest Maximum Load..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            long long result = sol.minMaximumLoad(tc.tasks, tc.k);
            
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
