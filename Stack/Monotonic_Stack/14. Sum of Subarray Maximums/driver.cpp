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
            { { {3, 1, 2, 4} }, 30 },
            { { {1, 2, 3} }, 14 },
            { { {1, 1, 1} }, 6 },
            { { {0, 6, -10, -6, -5, 0, 4, -2, -2, -10, 20} }, 351 },
            { { {17, 12, -3} }, 72 },
            { { {-8, -4, 15, -5, 18, 17, 13, 6, 8, 20, 20, -5, 11, 18, 17} }, 2090 },
            { { {-2, 15, 20, 13, 15, 0, 19} }, 477 },
            { { {7, 17, -4, 19, 6, 2, -6, 9, 17, 19, -7} }, 1037 },
            { { {16, -3, 3, 20, 16, 7, -7, 6, 20, 16, 8, -8} }, 1317 },
            { { {-5, -4, 6, 2, 5, 6, 16, 16, 11} }, 468 },
            { { {-6, 10, 4} }, 38 },
            { { {-1, 8, 16, 3, 17, 15} }, 299 },
            { { {0, 13, 1, -2, -8, -2, 2, 4, 6, 5, 8, -8, 6, 14, 18, -8, 3, 3, 4} }, 2210 },
            { { {-1, 4, 0, -6, 2} }, 31 },
            { { {-4, 3, 16, 9, -6} }, 158 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Sum of Subarray Maximums..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.sumSubarrayMaxs(tc.inputs.arr);
            
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
