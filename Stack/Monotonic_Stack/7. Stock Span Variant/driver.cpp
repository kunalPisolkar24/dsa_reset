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
        vector<int> prices;
    } inputs;
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { { {100, 80, 60, 70, 60, 75, 85} }, {1, 1, 1, 2, 1, 4, 6} },
            { { {10, 10, 10} }, {1, 2, 3} },
            { { {31, 41, 59, 26, 53, 58, 97} }, {1, 2, 3, 1, 2, 3, 7} },
            { { {107, 149, 100, 70, 77, 61, 57, 138, 130, 56, 146, 81, 89, 81, 103, 132, 97, 85, 129, 113} }, {1, 2, 1, 1, 2, 1, 1, 6, 1, 1, 9, 1, 2, 1, 4, 5, 1, 1, 3, 1} },
            { { {57, 91, 79, 116, 80, 64, 69, 74, 93, 88, 133, 119, 126, 127, 129, 72, 131} }, {1, 2, 1, 4, 1, 1, 2, 3, 5, 1, 11, 1, 2, 3, 4, 1, 6} },
            { { {110, 67, 101} }, {1, 1, 2} },
            { { {112, 78, 139, 118, 56, 115, 148, 118, 99, 142, 117, 148, 70, 62, 53, 102, 54} }, {1, 1, 3, 1, 1, 2, 7, 1, 1, 3, 1, 12, 1, 1, 1, 4, 1} },
            { { {75, 60, 69, 75, 97, 123, 69, 64, 102, 70, 132, 85, 142} }, {1, 1, 2, 4, 5, 6, 1, 1, 3, 1, 11, 1, 13} },
            { { {66} }, {1} },
            { { {95, 127, 66, 126, 61, 62, 131, 58, 123, 121, 55, 116, 53, 106, 103, 146, 59, 55, 58, 102} }, {1, 2, 1, 2, 1, 2, 7, 1, 2, 1, 1, 2, 1, 2, 1, 16, 1, 1, 2, 4} },
            { { {104, 117, 94, 63, 150} }, {1, 2, 1, 1, 5} },
            { { {99, 99, 147, 107, 121, 86, 147, 73} }, {1, 2, 3, 1, 2, 1, 7, 1} },
            { { {57, 66, 56, 65, 75, 108, 133} }, {1, 2, 1, 2, 5, 6, 7} },
            { { {62, 62, 127, 100, 144, 93, 119, 77, 50, 135, 76} }, {1, 2, 3, 1, 5, 1, 2, 1, 1, 5, 1} },
            { { {79, 147, 92} }, {1, 2, 1} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Stock Span Variant..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.stockSpan(tc.inputs.prices);
            
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
