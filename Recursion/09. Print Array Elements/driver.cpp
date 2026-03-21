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
    vector<int> arr;
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5} },
            { {5}, {5} },
            { {-1, -2, -3}, {-1, -2, -3} },
            { {10, 20}, {10, 20} },
            { {0, 0, 0, 0}, {0, 0, 0, 0} },
            { {1, -1, 1, -1}, {1, -1, 1, -1} },
            { {7, 8, 9, 10, 11}, {7, 8, 9, 10, 11} },
            { {100}, {100} },
            { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} },
            { {-5, 4, -3, 2, -1}, {-5, 4, -3, 2, -1} },
            { {42, 42, 42}, {42, 42, 42} },
            { {1, 3, 5, 7, 9}, {1, 3, 5, 7, 9} },
            { {2, 4, 6, 8, 10}, {2, 4, 6, 8, 10} },
            { {9, 8, 7, 6, 5}, {9, 8, 7, 6, 5} },
            { {0}, {0} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Print Array Elements..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.printArray(tc.arr);
            
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
