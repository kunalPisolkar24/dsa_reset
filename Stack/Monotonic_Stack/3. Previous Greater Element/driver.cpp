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
            { { {4, 5, 2, 10, 8} }, {-1, -1, 5, -1, 10} },
            { { {10, 4, 5, 2} }, {-1, 10, 10, 5} },
            { { {1, 2, 3} }, {-1, -1, -1} },
            { { {16} }, {-1} },
            { { {13, -3, 8, -7, -6, 14, 1, 13, 9, -5, 6, 3, 4, -6, 19, -5} }, {-1, 13, 13, 8, 8, -1, 14, 14, 13, 9, 9, 6, 6, 4, -1, 19} },
            { { {-5, 3, 2, -6, 9, 0, 8, 2} }, {-1, -1, 3, 2, -1, 9, 9, 8} },
            { { {-5, 5, 16, 17, -5, 14, 18, 8, 7, 8, -1, 10, -7, 4} }, {-1, -1, -1, -1, 17, 17, -1, 18, 8, 18, 8, 18, 10, 10} },
            { { {17, -9, 11, 5, 3, 9, 9, 6, -3, 10, 4, -2, 6, -7, -6, 15, -9, 19, -6, 18} }, {-1, 17, 17, 11, 5, 11, 11, 9, 6, 11, 10, 4, 10, 6, 6, 17, 15, -1, 19, 19} },
            { { {2, 9, 11, -1, -10, 8, 3, 12, 4, 16, 17, 2, 13, 11, -1} }, {-1, -1, -1, 11, -1, 11, 8, -1, 12, -1, -1, 17, 17, 13, 11} },
            { { {-3, 4, 18, -10, 9} }, {-1, -1, -1, 18, 18} },
            { { {6, 6, -10, -10, -4, -2, -8, 12, 2, -10, 17, 15, 4, -7, -7, 9} }, {-1, -1, 6, 6, 6, 6, -2, -1, 12, 2, -1, 17, 15, 4, 4, 15} },
            { { {20, 3, 7, 18, 8} }, {-1, 20, 20, 20, 18} },
            { { {6, 8, 12, 9, 3, 14, 16, 8, -6} }, {-1, -1, -1, 12, 9, -1, -1, 16, 8} },
            { { {-5, 1, 8, 19, 7, 19} }, {-1, -1, -1, -1, 19, -1} },
            { { {4, 3} }, {-1, 4} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Previous Greater Element..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.previousGreater(tc.inputs.arr);
            
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
