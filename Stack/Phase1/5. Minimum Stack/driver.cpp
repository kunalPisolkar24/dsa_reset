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
    vector<string> ops;
    vector<int> args;
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {"push", "push", "push", "getMin", "pop", "top", "getMin"},
              {-2, 0, -3, 0, 0, 0, 0},
              {-1, -1, -1, -3, -1, 0, -2} },
            { {"push", "getMin"}, {5, 0}, {-1, 5} },
            { {"push", "push", "getMin", "pop", "getMin"},
              {10, 20, 0, 0, 0},
              {-1, -1, 10, -1, 10} },
            { {"push", "push", "getMin", "pop", "getMin"},
              {20, 10, 0, 0, 0},
              {-1, -1, 10, -1, 20} },
            { {"push", "push", "push", "getMin", "pop", "getMin", "pop", "getMin"},
              {1, 2, 3, 0, 0, 0, 0, 0},
              {-1, -1, -1, 1, -1, 1, -1, 1} },
            { {"push", "push", "push", "getMin", "pop", "getMin", "pop", "getMin"},
              {3, 2, 1, 0, 0, 0, 0, 0},
              {-1, -1, -1, 1, -1, 2, -1, 3} },
            { {"push", "push", "push", "getMin"},
              {0, 0, 0, 0},
              {-1, -1, -1, 0} },
            { {"push", "top", "getMin", "pop", "push", "getMin"},
              {-1000, 0, 0, 0, 1000, 0},
              {-1, -1000, -1000, -1, -1, 1000} },
            { {"push", "push", "top", "getMin"},
              {5, -5, 0, 0},
              {-1, -1, -5, -5} },
            { {"push", "top", "push", "top", "getMin"},
              {42, 0, 42, 0, 0},
              {-1, 42, -1, 42, 42} },
            { {"push", "push", "push", "push", "getMin"},
              {10, 9, 8, 7, 0},
              {-1, -1, -1, -1, 7} },
            { {"push", "push", "push", "push", "getMin"},
              {7, 8, 9, 10, 0},
              {-1, -1, -1, -1, 7} },
            { {"push", "pop", "push", "getMin"},
              {10, 0, 20, 0},
              {-1, -1, -1, 20} },
            { {"push", "push", "getMin"},
              {-1, -2, 0},
              {-1, -1, -2} },
            { {"push", "push", "pop", "push", "getMin", "top"},
              {1, 2, 0, -1, 0, 0},
              {-1, -1, -1, -1, -1, -1} }
        };

        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Minimum Stack..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            MinStack minStack;
            vector<int> result;
            for (int k = 0; k < tc.ops.size(); k++) {
                if (tc.ops[k] == "push") {
                    minStack.push(tc.args[k]);
                    result.push_back(-1);
                } else if (tc.ops[k] == "pop") {
                    minStack.pop();
                    result.push_back(-1);
                } else if (tc.ops[k] == "top") {
                    result.push_back(minStack.top());
                } else if (tc.ops[k] == "getMin") {
                    result.push_back(minStack.getMin());
                }
            }
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: [";
                for(int j=0; j<tc.expected.size(); j++) cout << tc.expected[j] << (j == tc.expected.size()-1 ? "" : ", ");
                cout << "]" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: [";
                for(int j=0; j<result.size(); j++) cout << result[j] << (j == result.size()-1 ? "" : ", ");
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
