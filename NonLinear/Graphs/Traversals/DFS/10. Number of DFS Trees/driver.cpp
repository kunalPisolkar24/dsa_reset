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
            { 7, {{2, 4}, {1, 2}, {0, 3}, {0, 6}, {2, 3}, {2, 6}, {5, 6}, {3, 6}, {3, 5}}, 1 },
            { 7, {{0, 1}, {0, 4}, {4, 6}, {0, 3}, {2, 6}}, 2 },
            { 10, {{3, 4}, {2, 7}, {6, 8}, {0, 3}, {2, 3}, {6, 7}, {4, 5}, {3, 9}, {1, 6}}, 1 },
            { 25, {{3, 4}, {3, 7}, {0, 2}, {14, 22}, {17, 18}, {11, 14}, {0, 14}, {10, 15}, {1, 18}, {6, 23}, {5, 6}, {3, 21}, {0, 1}, {4, 23}, {9, 22}, {11, 19}, {19, 20}, {4, 16}, {0, 3}, {8, 13}, {0, 12}, {11, 15}, {0, 24}, {13, 24}}, 1 },
            { 12, {{2, 4}, {5, 11}, {2, 7}, {5, 8}, {2, 10}, {0, 6}, {2, 3}, {5, 6}, {1, 6}, {1, 9}}, 2 },
            { 23, {{16, 20}, {5, 22}, {11, 14}, {0, 11}, {2, 8}, {11, 20}, {6, 20}, {4, 20}, {11, 16}, {1, 5}, {11, 19}, {1, 20}, {2, 19}, {13, 19}, {7, 12}, {15, 19}, {18, 21}, {9, 12}, {17, 19}, {0, 3}, {8, 22}, {1, 10}, {0, 18}, {7, 11}, {7, 14}}, 1 },
            { 10, {{0, 1}, {0, 7}, {3, 8}, {4, 6}, {5, 7}, {7, 9}, {2, 3}, {4, 5}, {8, 9}, {1, 7}, {3, 9}, {0, 5}, {5, 9}, {2, 5}, {6, 9}}, 1 },
            { 4, {{0, 1}, {1, 2}, {0, 3}, {2, 3}, {0, 2}}, 1 },
            { 20, {{12, 16}, {14, 16}, {6, 11}, {5, 18}, {2, 7}, {2, 13}, {12, 14}, {3, 11}, {4, 10}, {3, 14}, {3, 17}, {5, 14}, {5, 8}, {0, 3}, {9, 15}, {1, 10}, {10, 19}, {6, 9}, {7, 14}}, 2 },
            { 2, {{0, 1}}, 1 },
            { 3, {{0, 2}, {1, 2}}, 1 },
            { 20, {{8, 15}, {9, 10}, {8, 14}, {1, 15}, {8, 10}, {2, 19}, {11, 12}, {6, 13}, {10, 16}, {2, 6}, {7, 12}, {0, 15}, {8, 18}, {4, 17}, {5, 12}, {3, 5}, {7, 14}}, 3 },
            { 10, {{1, 2}, {4, 9}, {6, 8}, {0, 3}, {2, 3}, {7, 9}, {4, 5}, {8, 9}, {6, 7}}, 2 },
            { 3, {{0, 1}, {1, 2}}, 1 },
            { 7, {{2, 4}, {1, 2}, {0, 6}, {2, 6}, {2, 5}, {1, 3}}, 1 }
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
