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
            { { {2, 1, 2, 4, 3} }, {3, 1, 1, -1, -1} },
            { { {73, 74, 75, 71, 69, 72, 76, 73} }, {1, 1, 4, 2, 1, 1, -1, -1} },
            { { {1, 1, 1} }, {-1, -1, -1} },
            { { {5, -9, -1} }, {-1, 1, -1} },
            { { {15, 19} }, {1, -1} },
            { { {-3, -7, -4, 18, 14, 18, 8, -5, -8, 12} }, {3, 1, 1, -1, 1, -1, 3, 2, 1, -1} },
            { { {-10, -6, 17, 7, 17, -5, -7, -7, -7, 10} }, {1, 1, -1, 1, -1, 4, 3, 2, 1, -1} },
            { { {6, -2} }, {-1, -1} },
            { { {-3} }, {-1} },
            { { {0, 7, 15, 0, 15, -4, 18, 3, 7, 16, -9, -6, 20, -8, 4} }, {1, 1, 4, 1, 2, 1, 6, 1, 1, 3, 1, 1, -1, 1, -1} },
            { { {10, 9} }, {-1, -1} },
            { { {-5, 1, -2, 13} }, {1, 2, 1, -1} },
            { { {-10, 9, -5, 20, 4, 17, 18, 4, 13, 14, 11, 12, 8, 15, 15, -1} }, {1, 2, 1, -1, 1, 1, -1, 1, 1, 4, 1, 2, 1, -1, -1, -1} },
            { { {2, -3, 4} }, {2, 1, -1} },
            { { {13, 10, 9, 19, -10, 11, 12, -5, -9} }, {3, 2, 1, -1, 1, 1, -1, -1, -1} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Distance to Next Greater..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.distanceToNextGreater(tc.inputs.arr);
            
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
