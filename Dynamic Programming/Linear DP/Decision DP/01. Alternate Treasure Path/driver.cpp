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
    vector<int> coins;
    long long expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            {{4, 2, 7, 9, 3}, 14},
            {{10, 1, 1, 10}, 20},
            {{5, 10, 15}, 20},
            {{1, 2, 3}, 4},
            {{100, 1, 1, 1, 100}, 201},
            {{1, 100, 1, 100, 1}, 200},
            {{5, 5, 5, 5}, 10},
            {{1, 1, 1, 1, 1}, 3},
            {{10, 0, 10, 0, 10}, 30},
            {{0, 10, 0, 10, 0}, 20},
            {{10, 20, 30, 40, 50}, 90},
            {{50, 40, 30, 20, 10}, 90},
            {{1, 2, 1, 2, 1, 2}, 6},
            {{2, 1, 2, 1, 2, 1}, 6},
            {{10, 1, 1, 1, 1, 10}, 21}
        };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Alternate Treasure Path..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            long long result = sol.maxCoins(tc.coins);

            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();

            bool passed = (result == tc.expected);

            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << tc.expected << ", Got: " << result << Color::RESET << "\n";
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
