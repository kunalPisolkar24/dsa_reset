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
            { { {1, 1, 2, 3, 4, 2, 1} }, {-1, -1, 1, 2, 2, 1, -1} },
            { { {1, 2, 1, 2, 1, 2} }, {-1, -1, -1, -1, -1, -1} },
            { { {4, 4, 4, 3, 2, 1} }, {-1, -1, -1, -1, -1, -1} },
            { { {-6, 14, 6, 1, -3, 10, -2, 11, 18, 9, 3, 17, 7, 20, 5} }, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1} },
            { { {17, -1, 4, -1, -8, 18, -9, -7, 14, 2, -3, 20, 2, 5, -5} }, {-1, -1, -1, -1, 2, 2, 2, 2, 2, -1, 2, 2, -1, -1, -1} },
            { { {-2, 6, 7, 5, -5, -4, 20, -7, 16, -5, -10, -7, 4} }, {-5, -5, -5, -5, -1, -7, -7, -1, -5, -1, -7, -1, -1} },
            { { {5, 7, 19, -1, 3, 12, 20, 7, 12, 3, 19} }, {7, -1, -1, 3, -1, -1, 7, -1, -1, -1, -1} },
            { { {5, 8, 17, 10, 3, -2} }, {-1, -1, -1, -1, -1, -1} },
            { { {-4, 1, -8, 7, -2} }, {-1, -1, -1, -1, -1} },
            { { {1, 11, -9, -10, 13, 11, 1, 0, 1, 9, 14, 13, -2, 2, 3, 15, 4, -1} }, {-1, 1, 13, 13, 1, 1, -1, 1, -1, 13, 13, -1, -1, -1, -1, -1, -1, -1} },
            { { {-8, 16, -3, 15, 19, -8, 13, -8, 13, 8, 14, 4, 14, 3, 18, 14, 9, 12} }, {-1, -8, -8, -8, -8, -1, -8, -1, 14, 14, -1, 14, -1, 14, 14, -1, -1, -1} },
            { { {18, 15, 9, -1, 20, 6, 4, 10, 16, -9, 3, 11, -8, 6, 7, 1, 15, 0, 8, 14} }, {15, -1, 6, 6, 6, -1, 6, 6, 6, 6, 6, 6, 6, -1, 15, 15, -1, -1, -1, -1} },
            { { {11, 12, 13, 5, -7, 5, 19, 3, 2, 4, 9} }, {5, 5, 5, -1, 5, -1, -1, -1, -1, -1, -1} },
            { { {6, -1, 8, 20, 17, 9, 4, -2, 8, 7} }, {8, 8, -1, 8, 8, 8, 8, 8, -1, -1} },
            { { {16, 11} }, {-1, -1} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Next Greater Frequency..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.nextGreaterFrequency(tc.inputs.arr);
            
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
