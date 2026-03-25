#include <bits/stdc++.h>

#ifdef USE_REFERENCE_SOLUTION
#include "ReferenceSolution.cpp"
#else
#include "Solution.cpp"
#endif

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
    int n;
    bool expected;
};

class ValueFormatter {
public:
    static string format(bool value) {
        return value ? "true" : "false";
    }
};

class TestRunner {
public:
    void run() {
        const vector<TestCase> cases = {
            {0, false},
            {1, true},
            {2, false},
            {3, true},
            {14, false},
            {27, true},
            {100, false},
            {999, true},
            {-1, true},
            {-2, false},
            {-15, true},
            {-20, false},
            {1000000000, false},
            {999999999, true},
            {-999999999, true}
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = static_cast<int>(cases.size());

        cout << Color::BOLD << "Running " << totalCount << " Tests for Odd or Even..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; ++i) {
            const TestCase& tc = cases[i];

            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            bool result = sol.isOdd(tc.n);

            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();

            bool passed = (result == tc.expected);

            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                ++passedCount;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Input: n = " << tc.n << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << ValueFormatter::format(tc.expected) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: " << ValueFormatter::format(result) << Color::RESET << "\n";
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
