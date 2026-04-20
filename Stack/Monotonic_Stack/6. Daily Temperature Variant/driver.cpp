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
        vector<int> temps;
    } inputs;
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { { {30, 32, 33, 31, 36} }, {4, 3, 2, 1, -1} },
            { { {10, 20, 30} }, {1, 1, -1} },
            { { {30, 30, 30} }, {-1, -1, -1} },
            { { {89, 71, 78, 75} }, {-1, 1, -1, -1} },
            { { {49, 92, 46, 95, 41, 90, 75, 99, 86, 76, 96, 44, 93, 36, 41, 96} }, {1, 2, 1, 4, 1, 2, 1, -1, 2, 1, -1, 1, 3, 1, 1, -1} },
            { { {50, 66, 63, 46, 64, 67, 57, 69, 54, 85, 83, 48, 71, 80, 94} }, {1, 8, 3, 1, 1, 4, 1, 2, 1, 5, 4, 1, 1, 1, -1} },
            { { {38, 35, 93, 68, 84, 90, 83, 91, 42, 85, 68, 80, 67, 44, 40, 74, 46} }, {2, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 3, 2, 1, -1, -1} },
            { { {32, 65, 94, 35, 32, 64, 81, 94, 68, 72, 63, 58, 83, 75} }, {1, 1, -1, 2, 1, 1, 1, -1, 1, 3, 2, 1, -1, -1} },
            { { {40, 86, 50, 48, 81, 56, 92, 57, 37, 71, 85, 40, 86, 59, 55, 55} }, {1, 5, 2, 1, 2, 1, -1, 2, 1, 1, -1, 1, -1, -1, -1, -1} },
            { { {73, 78, 79} }, {1, -1, -1} },
            { { {84, 44, 47, 63, 89, 30, 64, 86, 60, 81, 79, 49, 89, 96} }, {4, 1, 1, 1, 9, 1, 1, 5, 1, 3, 2, 1, 1, -1} },
            { { {92, 85, 63, 40, 34} }, {-1, -1, -1, -1, -1} },
            { { {48, 62, 95, 95, 87, 78, 42, 41} }, {1, 1, -1, -1, -1, -1, -1, -1} },
            { { {94, 100, 89, 56, 59} }, {1, -1, -1, 1, -1} },
            { { {78, 88, 77, 64, 79, 49, 82, 81, 82, 42, 32, 50, 77, 89, 89, 30, 44, 82} }, {1, -1, 4, 1, 2, 1, 7, 6, 5, 2, 1, 1, 1, -1, -1, 1, 1, -1} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Daily Temperature Variant..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.dailyTempVariant(tc.inputs.temps);
            
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
