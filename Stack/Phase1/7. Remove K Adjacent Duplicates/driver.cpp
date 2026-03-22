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
    string s;
    int k;
    string expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { "abcd", 2, "abcd" },
            { "deeedbbcccbdaa", 3, "aa" },
            { "pbbcggttciiippooaais", 2, "ps" },
            { "aa", 2, "" },
            { "aaa", 2, "a" },
            { "aaa", 3, "" },
            { "aabbba", 3, "" },
            { "abbba", 3, "aa" },
            { "yfttttfbbbaaacv", 4, "yffbbbaaacv" },
            { "yfttttfbbbaaacv", 3, "yftfcv" },
            { "nnwsssvvvvvvvnnbeomllis", 7, "nnwsssnnbeomllis" },
            { "wild", 5, "wild" },
            { "aaabbbccc", 3, "" },
            { "abc", 10, "abc" },
            { "baaaab", 4, "bb" }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Remove K Adjacent Duplicates..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            string result = sol.removeDuplicates(tc.s, tc.k);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Input: s=\"" << tc.s << "\", k=" << tc.k << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: \"" << tc.expected << "\"" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: \"" << result << "\"" << Color::RESET << "\n";
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
            cout << Color::GREEN << Color::BOLD << "  ALL TESTS PASSED! (" << passedCount << "/" << totalCount << ")" << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)" << Color::RESET << "\n";
        }
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
    }
};

int main() {
    TestRunner runner;
    runner.run();
    return 0;
}
