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
    int i;
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
            {0, 0, false},
            {1, 0, true},
            {1, 1, false},
            {5, 0, true},
            {5, 1, false},
            {5, 2, true},
            {8, 3, true},
            {8, 2, false},
            {42, 1, true},
            {42, 0, false},
            {255, 7, true},
            {255, 8, false},
            {1024, 10, true},
            {1024, 9, false},
            {1073741824, 30, true}
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = static_cast<int>(cases.size());

        cout << Color::BOLD << "Running " << totalCount << " Tests for Check Bit..." << Color::RESET << "\n\n";

        for (int index = 0; index < totalCount; ++index) {
            const TestCase& tc = cases[index];

            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            bool result = sol.isBitSet(tc.n, tc.i);

            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();

            bool passed = (result == tc.expected);

            if (passed) {
                cout << Color::GREEN << "✓ Test " << index + 1 << " Passed" << Color::RESET << "\n";
                ++passedCount;
            } else {
                cout << Color::RED << "✗ Test " << index + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Input: n = " << tc.n << ", i = " << tc.i << Color::RESET << "\n";
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
