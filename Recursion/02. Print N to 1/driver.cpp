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
    int n;
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 5, {5, 4, 3, 2, 1} },
            { 1, {1} },
            { 2, {2, 1} },
            { 3, {3, 2, 1} },
            { 10, {10, 9, 8, 7, 6, 5, 4, 3, 2, 1} },
            { 4, {4, 3, 2, 1} },
            { 6, {6, 5, 4, 3, 2, 1} },
            { 7, {7, 6, 5, 4, 3, 2, 1} },
            { 8, {8, 7, 6, 5, 4, 3, 2, 1} },
            { 9, {9, 8, 7, 6, 5, 4, 3, 2, 1} },
            { 15, {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1} },
            { 11, {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1} },
            { 12, {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1} },
            { 13, {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1} },
            { 14, {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Print N to 1..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.printNTo1(tc.n);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: [";
                for(size_t j = 0; j < tc.expected.size(); j++) cout << tc.expected[j] << (j == tc.expected.size()-1 ? "" : ", ");
                cout << "]" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: [";
                for(size_t j = 0; j < result.size(); j++) cout << result[j] << (j == result.size()-1 ? "" : ", ");
                cout << "]" << Color::RESET << "\n";
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
