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
    vector<int> target;
    int n;
    vector<string> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {1, 3}, 3, {"Push", "Push", "Pop", "Push"} },
            { {1, 2, 3}, 3, {"Push", "Push", "Push"} },
            { {1, 2}, 4, {"Push", "Push"} },
            { {2, 3, 4}, 4, {"Push", "Pop", "Push", "Push", "Push"} },
            { {1}, 10, {"Push"} },
            { {5}, 5, {"Push", "Pop", "Push", "Pop", "Push", "Pop", "Push", "Pop", "Push"} },
            { {2, 4}, 5, {"Push", "Pop", "Push", "Push", "Pop", "Push"} },
            { {1, 4}, 4, {"Push", "Push", "Pop", "Push", "Pop", "Push"} },
            { {2}, 2, {"Push", "Pop", "Push"} },
            { {1, 2, 4}, 4, {"Push", "Push", "Push", "Pop", "Push"} },
            { {3}, 3, {"Push", "Pop", "Push", "Pop", "Push"} },
            { {1, 5}, 5, {"Push", "Push", "Pop", "Push", "Pop", "Push", "Pop", "Push"} },
            { {4}, 5, {"Push", "Pop", "Push", "Pop", "Push", "Pop", "Push"} },
            { {1, 2, 3, 4}, 4, {"Push", "Push", "Push", "Push"} },
            { {2, 3}, 3, {"Push", "Pop", "Push", "Push"} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Build Array With Stack Operations..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<string> result = sol.buildArray(tc.target, tc.n);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Input: target=[";
                for(int j=0; j<tc.target.size(); j++) cout << tc.target[j] << (j == tc.target.size()-1 ? "" : ",");
                cout << "], n=" << tc.n << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: [";
                for(int j=0; j<tc.expected.size(); j++) cout << "\"" << tc.expected[j] << "\"" << (j == tc.expected.size()-1 ? "" : ",");
                cout << "]" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: [";
                for(int j=0; j<result.size(); j++) cout << "\"" << result[j] << "\"" << (j == result.size()-1 ? "" : ",");
                cout << "]" << Color::RESET << "\n";
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
