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
            { {1, 2, 3, 4}, {4, 3, 2, 1} },
            { {1, 2, 3, 4, 5}, {5, 4, 3, 2, 1} },
            { {5}, {5} },
            { {-1, -2, -3}, {-3, -2, -1} },
            { {10, 20}, {20, 10} },
            { {0, 0, 0, 0}, {0, 0, 0, 0} },
            { {1, -1, 1, -1}, {-1, 1, -1, 1} },
            { {7, 8, 9, 10, 11}, {11, 10, 9, 8, 7} },
            { {100}, {100} },
            { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {10, 9, 8, 7, 6, 5, 4, 3, 2, 1} },
            { {-5, 4, -3, 2, -1}, {-1, 2, -3, 4, -5} },
            { {42, 42, 42}, {42, 42, 42} },
            { {1, 3, 5, 7, 9}, {9, 7, 5, 3, 1} },
            { {2, 4, 6, 8, 10}, {10, 8, 6, 4, 2} },
            { {}, {} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Reverse an Array (In-place)..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> inputCopy = tc.arr;
            sol.reverseArray(inputCopy);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (inputCopy == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: [";
                for(size_t j = 0; j < tc.expected.size(); j++) cout << tc.expected[j] << (j == tc.expected.size()-1 ? "" : ", ");
                cout << "]" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: [";
                for(size_t j = 0; j < inputCopy.size(); j++) cout << inputCopy[j] << (j == inputCopy.size()-1 ? "" : ", ");
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
