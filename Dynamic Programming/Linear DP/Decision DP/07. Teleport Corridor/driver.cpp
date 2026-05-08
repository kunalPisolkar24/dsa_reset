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
    vector<int> power;
    long long expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            {{4, 0, -2, 8, -1, 5}, 16},
            {{10, 10, 10, 10, 10}, 50},
            {{5, -10, -10, -10, 20}, 15},
            {{10, -1, -1, -1, -1, 10}, 18},
            {{1, 1, 1, 1, 1}, 5},
            {{10, -100, -100, 10, -100, -100, 10}, 30},
            {{0, 0, 0, 0, 0}, 0},
            {{1, 2, 3, 4, 5}, 15},
            {{10, -5, -5, -5, -5, -5, 100}, 105},
            {{10, -1, -1, 10, -1, -1, 10}, 30},
            {{-10, -10, -10}, -10},
            {{5, -2, -2, -2, 5}, 8},
            {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10},
            {{100, -50, -50, -50, 100}, 150},
            {{10, -2, -2, 10}, 20}
        };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Teleport Corridor..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            long long result = sol.maxPower(tc.power);

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
