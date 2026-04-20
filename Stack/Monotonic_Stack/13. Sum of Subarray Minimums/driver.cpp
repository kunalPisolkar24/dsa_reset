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
            { { {3, 1, 2, 4} }, 17 },
            { { {11, 81, 94, 43, 3} }, 444 },
            { { {1, 2, 3} }, 10 },
            { { {11, -7, 18, 7, -8, -7, 18, 8} }, -146 },
            { { {9, 4, 13, -5, 12, -4, 0} }, -46 },
            { { {-4, -8, 15, 7, 12, 14, 11, 16, 14, 4, 3, -1, -7, 17} }, -20 },
            { { {2, 11, 18, -7, 4, 1, 7, -3, -3, -1, 14, 6, -8, 19, 2, 0, -10, 3, -3} }, -1146 },
            { { {-10, 7, 14, -7, 17, -2, 12, -3, 14, 13, 14, -2, 17, -7, 17, 11, -2} }, -653 },
            { { {6, 4, 11, 10, 18, -4, 20, 20, 4, 7, 3, 0, 12} }, 33 },
            { { {-2, -8, 20, -10, 20} }, -74 },
            { { {-9, 1, -6, -5, 7, 6} }, -97 },
            { { {2} }, 2 },
            { { {-7, 3, 7, -5} }, -30 },
            { { {16, 17, 11, 6, 6, 17, -3, 8, 4, 17, -8} }, 52 },
            { { {10, 7, 4, 3, 10, 5, 11, 17, -3, -8, 14, 12, -1} }, -137 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Sum of Subarray Minimums..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.sumSubarrayMins(tc.inputs.arr);
            
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
