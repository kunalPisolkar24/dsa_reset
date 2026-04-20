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
            { { {3, 7, 8, 3, 6, 1} }, {7, 8, -1, 6, -1, -1} },
            { { {1, 2, 3, 4} }, {2, 3, 4, -1} },
            { { {5, 4, 3, 2, 1} }, {-1, -1, -1, -1, -1} },
            { { {10, 15, 5, -10, -8, -7, -8} }, {15, -1, -1, -8, -7, -1, -1} },
            { { {17, 3, -1, 12, 6, 13, 8, -3, 19, 18, 16} }, {19, 12, 12, 13, 13, 19, 19, 19, -1, -1, -1} },
            { { {-10, 18, 7, -6, 17, 13, 6, -4} }, {18, -1, 17, 17, -1, -1, -1, -1} },
            { { {5, 12, 14, 15, -4, 2, 13, 20, 14, -5, 1} }, {12, 14, 15, 20, 2, 13, 20, -1, -1, 1, -1} },
            { { {5, 12, 17, 15, -10, 17, -4, -2, -7, 4, 4, -9, -7, 10, 19} }, {12, 17, 19, 17, 17, 19, -2, 4, 4, 10, 10, -7, 10, 19, -1} },
            { { {-5, -9, 19, -8, 6, 13, 10, 3, -3, 11, -6, 18, 18, 9, -9, 1} }, {19, 19, -1, 6, 13, 18, 11, 11, 11, 18, 18, -1, -1, -1, 1, -1} },
            { { {14, -3, 4, -10, 10, 17, 5, -5, 2, -1, -3, 0, 4, 4, -10, 3, 16, -9, 19} }, {17, 4, 10, 10, 17, 19, 16, 2, 4, 0, 0, 4, 16, 16, 3, 16, 19, 19, -1} },
            { { {5, 0, -10, 19, 18, -1, 1} }, {19, 19, 19, -1, -1, 1, -1} },
            { { {5, -8, 13, 20, -6, 20, -9, -7, -6, -3, -2} }, {13, 13, 20, -1, 20, -1, -7, -6, -3, -2, -1} },
            { { {6} }, {-1} },
            { { {7, -6, 6, 16, -1} }, {16, 6, 16, -1, -1} },
            { { {9, 17, 13, 17, 9, 20, 9, 3, -1, 11, 5} }, {17, 20, 17, 20, 20, -1, 11, 11, 11, -1, -1} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for First Taller Building..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.firstTallerBuilding(tc.inputs.heights);
            
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
