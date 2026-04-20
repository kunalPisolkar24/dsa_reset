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
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { { {2, 1, 5, 6, 2, 3} }, 10 },
            { { {2, 4} }, 4 },
            { { {1, 1, 1, 1} }, 4 },
            { { {12, -3, 11, -9, 17, 7, 12, -7, -9, -7, 4, 5, -10, 8} }, 21 },
            { { {-8, 11, -1, 3, 17, 14, -3, -2, 2, 7, -10, -4, -8, 20} }, 28 },
            { { {-6, -1, 0, -10, 4, 20, 20, 1, -1, 2, 2, -8, 5, 3, 16, 13, -3} }, 40 },
            { { {13, 1, 17, -4, 17, 11} }, 22 },
            { { {9, -1, 8, -1, 5, -8, 12, 1, 17, -9, 11, 17, 14, 6, 2, 2, 10, -3} }, 33 },
            { { {14, -8, 7, -6, 19, -6, 6, -1, -2, 15, 4, 1, -3} }, 19 },
            { { {8, 17, 9, 20, -4, 20, 13, -2, 15, 5} }, 32 },
            { { {-5, 13, 15, 11, 9, 19, 0, -7, 19, 19, -2, 12, 20} }, 45 },
            { { {13, -8, 5, 20, 16, 16, 19} }, 64 },
            { { {-4, -7, 10, -3, -8, -3, 16, -9, 19, 18, 9} }, 36 },
            { { {8, 3, -8} }, 8 },
            { { {14, 6, 19, 0, -9, -1, 8, 17, -4, 19, -1} }, 19 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Largest Rectangle in Histogram..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.largestRectangleArea(tc.inputs.heights);
            
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
