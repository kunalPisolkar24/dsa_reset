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
    int expected;
};

class ValueFormatter {
public:
    static string format(int value) {
        return to_string(value);
    }
};

class TestRunner {
public:
    void run() {
        const vector<TestCase> cases = {
            {0, 0},
            {1, 0},
            {2, 0},
            {3, 2},
            {4, 0},
            {5, 4},
            {6, 4},
            {7, 6},
            {8, 0},
            {12, 8},
            {40, 32},
            {42, 40},
            {73, 72},
            {255, 254},
            {1073741824, 0}
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = static_cast<int>(cases.size());

        cout << Color::BOLD << "Running " << totalCount << " Tests for Remove Last Set Bit..." << Color::RESET << "\n\n";

        for (int index = 0; index < totalCount; ++index) {
            const TestCase& tc = cases[index];

            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            int result = sol.removeLastSetBit(tc.n);

            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();

            bool passed = (result == tc.expected);

            if (passed) {
                cout << Color::GREEN << "✓ Test " << index + 1 << " Passed" << Color::RESET << "\n";
                ++passedCount;
            } else {
                cout << Color::RED << "✗ Test " << index + 1 << " Failed" << Color::RESET << "\n";
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
