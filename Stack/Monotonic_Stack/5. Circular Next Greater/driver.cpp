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
            { { {1, 2, 1} }, {2, -1, 2} },
            { { {5, 4, 3, 2, 1} }, {-1, 5, 5, 5, 5} },
            { { {1, 5, 3, 6, 8} }, {5, 6, 6, 8, -1} },
            { { {-2, 1, 6, 9, 19, -2, 6, 0, 19, 1, -2, -3, 2, 6, -8, -2} }, {1, 6, 9, 19, -1, 6, 19, 19, -1, 2, 2, 2, 6, 9, -2, 1} },
            { { {-9, 14, 19, 0, 2, -2} }, {14, 19, -1, 2, 14, 14} },
            { { {17, -4, -3, 12, 3, -1, -4} }, {-1, -3, 12, 17, 17, 17, 17} },
            { { {18, 1, -10, 18, -4, -8, 11, 14, 19, 19, 15, -10} }, {19, 18, 18, 19, 11, 11, 14, 19, -1, -1, 18, 18} },
            { { {9, 17, 13, 5, 19, 2, 0, 1, -2, 0, -10, 20, 2, -8, -2, 4, -8, -10} }, {17, 19, 19, 19, 20, 20, 1, 20, 0, 20, 20, -1, 4, -2, 4, 9, 9, 9} },
            { { {18, 6, 14, 5, -8, 20, 7, -9, -7, -5, 11, 20, 7, 12, 0, 6, -8, -10, 18} }, {20, 14, 20, 20, 20, -1, 11, -7, -5, 11, 20, -1, 12, 18, 6, 18, 18, 18, 20} },
            { { {15, -2, 17} }, {17, 17, -1} },
            { { {-1, -10, 4, 6, -9, 18, 7, 3, -10, 1, 8, 13, -3, 10, 2, -5, -9, 11} }, {4, 4, 6, 18, 18, -1, 8, 8, 1, 8, 13, 18, 10, 11, 11, 11, 11, 18} },
            { { {-3, 18, -8, -10, 14, 20, 10} }, {18, 20, 14, 14, 20, -1, 18} },
            { { {-8, 6, 3, 0} }, {6, -1, 6, 6} },
            { { {17, 8, 6, -5, 14} }, {-1, 14, 14, 14, 17} },
            { { {14, -1, -2, 18, 4, -2, 9, 8, 8, 16} }, {18, 18, 18, -1, 9, 9, 16, 16, 16, 18} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Circular Next Greater..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.nextGreaterCircular(tc.inputs.arr);
            
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
