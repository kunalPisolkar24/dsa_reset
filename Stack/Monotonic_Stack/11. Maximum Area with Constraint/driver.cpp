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
        int k;
    } inputs;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { { {2, 1, 5, 6, 2, 3}, 2 }, 10 },
            { { {10, 2, 10}, 1 }, 6 },
            { { {5, 5, 5}, 1 }, 15 },
            { { {3, 5, 9}, 2 }, 10 },
            { { {1, 4, 10, 2, 3, 10}, 5 }, 10 },
            { { {8, 9, 4, 10, 5, 8, 10, 2, 4, 9, 6, 8, 8, 3, 3, 3, 4, 7}, 9 }, 36 },
            { { {8, 6, 7, 7, 9, 3, 5, 9, 8, 9, 8, 1, 4, 8, 3, 2}, 8 }, 33 },
            { { {1, 2, 5, 8, 6, 9, 7, 3}, 3 }, 25 },
            { { {8, 9, 5}, 2 }, 15 },
            { { {1, 10, 6, 1, 6, 8, 7, 4, 3, 10, 9, 10, 7, 8}, 13 }, 35 },
            { { {4, 5, 4, 4, 1, 10, 9, 2, 2, 1, 5, 10, 7, 8, 9, 2, 3, 10, 1}, 7 }, 19 },
            { { {2, 6, 6, 7, 9, 7, 9, 8, 7, 1, 7, 9}, 0 }, 18 },
            { { {7, 9, 3, 6, 1, 7, 4, 8, 3, 6}, 0 }, 14 },
            { { {6, 3, 8, 6, 6, 4, 5, 10, 6, 4, 1, 6, 5, 10, 1, 8, 2, 10, 5}, 9 }, 32 },
            { { {2, 4, 8, 7, 9, 2, 5, 5, 5, 7, 6, 7, 8, 3, 4}, 11 }, 35 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Maximum Area with Constraint..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.maxAreaWithK(tc.inputs.heights, tc.inputs.k);
            
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
