#include <iostream>
#include <vector>
#include <sstream>
#include <string>
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
    int n;
    vector<vector<int>> edges;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 2, {}, 2 },
            { 20, {{10, 11}, {0, 11}, {6, 11}}, 17 },
            { 15, {{0, 13}, {6, 14}, {6, 7}, {3, 9}, {10, 12}}, 10 },
            { 3, {{0, 1}, {0, 2}}, 1 },
            { 19, {{0, 12}, {3, 17}}, 17 },
            { 13, {{1, 8}, {10, 11}, {8, 12}}, 10 },
            { 16, {{10, 15}, {2, 4}, {3, 14}, {2, 8}, {1, 15}, {2, 7}, {3, 11}, {4, 9}, {8, 10}, {7, 13}, {0, 6}, {4, 15}, {2, 6}, {2, 11}, {4, 7}, {12, 14}, {7, 14}}, 2 },
            { 5, {{0, 1}, {1, 3}, {2, 3}}, 2 },
            { 6, {}, 6 },
            { 9, {{0, 1}, {0, 7}, {5, 8}, {6, 8}, {0, 5}, {1, 3}, {3, 5}}, 3 },
            { 18, {{2, 16}, {11, 12}, {11, 15}, {12, 15}, {10, 12}, {0, 17}}, 13 },
            { 19, {{7, 17}, {6, 15}, {3, 7}, {4, 6}, {3, 10}, {5, 7}, {4, 18}, {2, 5}, {2, 11}, {13, 14}, {1, 18}, {11, 16}, {2, 7}, {11, 13}, {7, 15}, {3, 11}, {5, 8}, {5, 17}, {1, 13}, {16, 17}}, 4 },
            { 18, {{5, 7}, {5, 13}, {5, 10}, {11, 14}, {10, 12}, {1, 3}, {2, 17}, {6, 11}, {6, 14}, {7, 13}, {5, 6}, {3, 12}, {0, 10}, {1, 5}, {10, 14}, {3, 11}, {3, 14}, {14, 17}, {2, 9}, {2, 12}}, 5 },
            { 19, {{4, 5}, {2, 10}, {7, 12}, {3, 9}}, 15 },
            { 12, {}, 12 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countDFSTrees(tc.n, tc.edges);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << tc.expected << Color::RESET << "\n";\
                cout << "     " << Color::RED << "Got:      " << result << Color::RESET << "\n";
            }
            
            if (!logs.empty()) {
                cout << Color::YELLOW << "   Logs:" << Color::RESET << "\n";
                stringstream logStream(logs);
                string line;
                while (getline(logStream, line)) {
                    cout << "     " << line << "\n";
                }
            }
            
            cout << "\n";
        }
        
        printSummary(passedCount, totalCount);
    }

private:
    void printSummary(int passedCount, int totalCount) {
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
        if (passedCount == totalCount) {
            cout << Color::GREEN << Color::BOLD << "  ALL TESTS PASSED! (" << passedCount << "/" << totalCount << ")" << Color::RESET << "\n";
            cout << Color::GREEN << "  (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧" << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)" << Color::RESET << "\n";
            cout << Color::RED << "  (╯°□°）╯︵ ┻━┻" << Color::RESET << "\n";
        }
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
    }
};

int main() {
    TestRunner runner;
    runner.run();
    return 0;
}
