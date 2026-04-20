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
        vector<int> heights;
    } inputs;
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { { {10, 6, 8, 5, 11, 9} }, {3, 1, 2, 1, 1, 0} },
            { { {5, 1, 2, 3, 10} }, {4, 1, 1, 1, 0} },
            { { {1, 2, 3, 4} }, {1, 1, 1, 0} },
            { { {-3, 18, -10, 12, 13, 14, -1} }, {1, 4, 1, 1, 1, 1, 0} },
            { { {-2, 3, 11, 10, 10, 7, -9} }, {1, 1, 2, 1, 1, 1, 0} },
            { { {-10, -2, 10, 5, 0, 6, 7, -2, 0, 2, -2, 18, -8, 7, 3, 16, 6, 1, -5, 10} }, {1, 1, 4, 2, 1, 1, 4, 1, 1, 2, 1, 3, 1, 2, 1, 2, 2, 2, 1, 0} },
            { { {3, -9, 15, 7, 10, 3, 6, 7} }, {2, 1, 2, 1, 3, 1, 1, 0} },
            { { {19, 10, 12, 9, 18, 14, 17, 20, 7, 5, 11, 1} }, {4, 1, 2, 1, 3, 1, 1, 2, 2, 1, 1, 0} },
            { { {3, -2, 8, -4, -8, -9, 12, 17, -9, 12, 19, -7, 11, 14, 5, 20, 4, 13, 14} }, {2, 1, 2, 2, 2, 1, 1, 3, 1, 1, 4, 1, 1, 2, 1, 3, 1, 1, 0} },
            { { {-8, 9, -9, 19, 1, -1, 10, -5, 6, -4, 17, 14, 19} }, {1, 2, 1, 4, 2, 1, 3, 1, 2, 1, 2, 1, 0} },
            { { {-3, 16, -2, 1, 4, 9, 4} }, {1, 4, 1, 1, 1, 1, 0} },
            { { {0, 6, 8, -2, 15, 19, 8, 10, -10, 19, 12} }, {1, 1, 2, 1, 1, 3, 1, 2, 1, 1, 0} },
            { { {6, 14, 18, -4, 8, 13, 15, -7, -7, -1, 9, 17, 15, -1, 18} }, {1, 1, 6, 1, 1, 1, 5, 1, 1, 1, 1, 2, 2, 1, 0} },
            { { {-10, -4, 11, 3, 9, -8, 7} }, {1, 1, 2, 1, 2, 1, 0} },
            { { {6, 9, -1, 19, -6, 12, 19, -6, 12, -2, -9, 0, 12, 19, 11} }, {1, 2, 1, 3, 1, 1, 4, 1, 3, 2, 1, 1, 1, 1, 0} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Visible People in a Line..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.canSeePersonsCount(tc.inputs.heights);
            
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
