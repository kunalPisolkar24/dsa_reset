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
    long long low, high;
    vector<int> thresholds;
    long long limit;
    long long expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 1, 100, {10, 20, 30}, 6, 10 },
            { 1, 1000000000000LL, {1, 1, 1}, 3, 1 },
            { 1, 1000000000000LL, {10, 10, 10}, 1, -1 },
            { 1, 100, {5, 5, 5}, 10, 2 }, // ceil(5/2)=3, 3*3=9. ceil(5/1)=5, 3*5=15.
            { 1, 1000, {100, 200}, 5, 67 },
            { 1, 1000000000000LL, {1000000000}, 1, 1000000000 },
            { 10, 20, {100}, 5, 20 },
            { 10, 20, {100}, 10, 10 },
            { 1, 10, {1, 2, 3, 4, 5}, 15, 1 },
            { 1, 10, {1, 2, 3, 4, 5}, 5, 5 }, // 1+1+1+1+1=5. 4: 1+1+1+1+2=6.
            { 1, 1000000000000LL, {1, 2, 3}, 100, 1 },
            { 1, 2, {10}, 8, 2 }, // ceil(10/2)=5. ceil(10/1)=10.
            { 1, 5, {10}, 1, -1 }, // ceil(10/5)=2 (>1).
            { 1, 10, {2, 2, 2}, 3, 2 },
            { 1, 10, {2, 2, 2}, 4, 2 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for First Failing Point..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            long long result = sol.firstFailingPoint(tc.low, tc.high, tc.thresholds, tc.limit);
            
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
