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
            { { {4, 5, 2, 10, 8} }, {2, 2, -1, 8, -1} },
            { { {1, 2, 3} }, {-1, -1, -1} },
            { { {3, 2, 1} }, {2, 1, -1} },
            { { {-4, 11, 16, 9, 1, 4, 20, 18, -6, 16, 9, 5, 13, -2, 7} }, {-6, 9, 9, 1, -6, -6, 18, -6, -1, 9, 5, -2, -2, -1, -1} },
            { { {14, -6, 17, -8, 11, -9, 13, -2, 12} }, {-6, -8, -8, -9, -9, -1, -2, -1, -1} },
            { { {10, -1, -8, 18, 3, 15, 15, 8, 11, 13, 14} }, {-1, -8, -1, 3, -1, 8, 8, -1, -1, -1, -1} },
            { { {18} }, {-1} },
            { { {-3, 14, -6, 14, -5, -3, -6, 8} }, {-6, -6, -1, -5, -6, -6, -1, -1} },
            { { {3, -4, 15} }, {-4, -1, -1} },
            { { {-5, 3, 14, 20, 14, -2, 3, 8, 13, 7} }, {-1, -2, -2, 14, -2, -1, -1, 7, 7, -1} },
            { { {6, 11} }, {-1, -1} },
            { { {12, 6, -6, 14, -8, -3, 1, -10, -3} }, {6, -6, -8, -8, -10, -10, -10, -1, -1} },
            { { {-6, 16, 7, -8, 7, -1, -3, 9, -1, 6, 8, -6, 0, 10, 16, 2} }, {-8, 7, -8, -1, -1, -3, -6, -1, -6, -6, -6, -1, -1, 2, 2, -1} },
            { { {-8, -1, 13, 3, 2, 11, -4, 6, 20, 18, 2} }, {-1, -4, 3, 2, -4, -4, -1, 2, 18, 2, -1} },
            { { {20, -2, 1, 1, -5} }, {-2, -5, -5, -5, -1} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Next Smaller to Right..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.nextSmallerRight(tc.inputs.arr);
            
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
