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
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { { {1, 3, 1} }, 12 },
            { { {5, 4} }, 17 },
            { { {1, 2} }, 5 },
            { { {18} }, 18 },
            { { {4, 14, -4, 16, -4, 11, -9, -5, 0, 7, -6, -3} }, -2774 },
            { { {14, 18, -3, 19, 9, 13, 13, 6, -3, 11} }, -173 },
            { { {12, 7, 9, 18, 20, 7, 11, 10, 14, 20, -6, 7, 0, 13} }, -274 },
            { { {7, 5, 3, 3, 16, 6, 3, -4, 13, -1, 3, 11, 15, -8, 19} }, -2778 },
            { { {4} }, 4 },
            { { {14, -6, 5, 19, 16, 5, 0, 0, 11, 1, -1, 14, 16, 7, 8, -6, 10, 3, 15, 13} }, -6244 },
            { { {20, 2, 7, -3, 15} }, -14 },
            { { {5, 4, 20, 6, 5, -1, 11, 2, 19, -8, 14, -9, 2, 18, 9, -6, 4, 9, -4} }, -9821 },
            { { {20, -10, -8, 8, 10, 1, 1, 5, 15, 0, -3, -3, -6} }, -2649 },
            { { {9, 2, 6, 6, 12, -8, 0, 18, -7, 5, 0, -5, 15, 1, 12} }, -4604 },
            { { {12, 18, 18, 15, 17, 11, 19, -1, 17, 7, -5, 3, -7, -10} }, -1452 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Strength of Array..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.totalStrength(tc.inputs.arr);
            
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
