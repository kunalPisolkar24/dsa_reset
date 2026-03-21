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
            { 10, {2, 4, 6, 8, 10} },
            { 3, {2} },
            { 1, {} },
            { 2, {2} },
            { 4, {2, 4} },
            { 5, {2, 4} },
            { 6, {2, 4, 6} },
            { 7, {2, 4, 6} },
            { 8, {2, 4, 6, 8} },
            { 9, {2, 4, 6, 8} },
            { 14, {2, 4, 6, 8, 10, 12, 14} },
            { 15, {2, 4, 6, 8, 10, 12, 14} },
            { 20, {2, 4, 6, 8, 10, 12, 14, 16, 18, 20} },
            { 21, {2, 4, 6, 8, 10, 12, 14, 16, 18, 20} },
            { 100, {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Print Even Numbers from 1 to N..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.printEven(tc.n);
            
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
