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
    struct Inputs {
        vector<int> arr;
    } inputs;
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { { {4, 5, 2, 10} }, {5, 10, 10, -1} },
            { { {1, 2, 3, 4} }, {2, 3, 4, -1} },
            { { {4, 3, 2, 1} }, {-1, -1, -1, -1} },
            { { {20, -10, 2, 7, 14, -3, 18, 6, -5, -2, 14, 13, 20, -4, 6, -9, 16} }, {-1, 2, 7, 14, 18, 18, 20, 14, -2, 14, 20, 20, -1, 6, 16, 16, -1} },
            { { {17, 10, -6, -6, 15, 13, 0, 14, -8, 8, -6} }, {-1, 15, 15, 15, -1, 14, 14, -1, 8, -1, -1} },
            { { {10} }, {-1} },
            { { {6, 12, 6, 5, 5, 13, 8, 11, 10, 1, -3, 12, 13, -9} }, {12, 13, 13, 13, 13, -1, 11, 12, 12, 12, 12, 13, -1, -1} },
            { { {-3, 20, 11, -1, -4, 9, 12, 17, -8} }, {20, -1, 12, 9, 9, 12, 17, -1, -1} },
            { { {3, 10, -8} }, {10, -1, -1} },
            { { {1, 5, 15, 18, 19, 5, 18, -6, 0, 18, -2} }, {5, 15, 18, 19, -1, 18, -1, 0, 18, -1, -1} },
            { { {18, 17, 5, 7} }, {-1, -1, 7, -1} },
            { { {3, 11, 19, 19, -10, 15, 3, 13, 0, 8, 18, -4, 0} }, {11, 19, -1, -1, 15, 18, 13, 18, 8, 18, -1, 0, -1} },
            { { {19, 8, -7, 2, 16, -6, 3, 13, -1, -5, 13, 17, -2, 14, -7, -3, 2, -9, -10, 3} }, {-1, 16, 2, 16, 17, 3, 13, 17, 13, 13, 17, -1, 14, -1, -3, 2, 3, 3, 3, -1} },
            { { {14, 13, -2, 6, 19, 9, 18, 7, 11, -10, -10, 16, 9, -3, 2} }, {19, 19, 6, 19, -1, 18, -1, 11, 16, 16, 16, -1, -1, 2, -1} },
            { { {19, 14, 7, 16, 20, 1, 14, -6, 12, 20, 20, 13, -10, 15, -10, 0, 11} }, {20, 16, 16, 20, -1, 14, 20, 12, 20, -1, -1, 15, 15, -1, 0, 11, -1} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Next Greater to Right..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.nextGreaterRight(tc.inputs.arr);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << formatOutput(tc.expected) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got:      " << formatOutput(result) << Color::RESET << "\n";
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
    template<typename T>
    string formatOutput(const T& val) {
        stringstream ss;
        if constexpr (is_same_v<T, vector<int>> || is_same_v<T, vector<string>>) {
            ss << "[";
            for(size_t i=0; i<val.size(); ++i) {
                ss << val[i] << (i == val.size()-1 ? "" : ", ");
            }
            ss << "]";
        } else {
            ss << val;
        }
        return ss.str();
    }

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
