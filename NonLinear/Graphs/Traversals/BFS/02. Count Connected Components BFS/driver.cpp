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
            { 6, {{0, 1}, {0, 4}, {1, 5}, {0, 3}, {2, 3}, {0, 2}, {1, 3}, {3, 5}}, 1 },
            { 7, {{2, 4}, {0, 4}, {3, 4}, {0, 3}, {4, 5}, {5, 6}, {3, 6}, {2, 5}}, 2 },
            { 6, {{2, 4}, {1, 2}, {0, 4}, {3, 4}, {1, 4}, {2, 3}, {4, 5}, {0, 5}}, 1 },
            { 15, {{8, 14}, {3, 8}, {9, 13}, {5, 11}, {1, 11}, {2, 10}, {6, 14}, {4, 12}, {7, 13}, {2, 9}, {0, 5}, {4, 11}, {1, 3}, {2, 11}, {7, 8}}, 1 },
            { 16, {{6, 15}, {3, 4}, {3, 13}, {0, 2}, {8, 9}, {0, 8}, {2, 5}, {10, 12}, {2, 11}, {13, 14}, {5, 6}, {3, 15}, {5, 12}, {1, 11}, {3, 5}, {0, 3}, {0, 6}, {8, 13}, {2, 12}, {7, 11}, {7, 14}}, 1 },
            { 7, {{0, 1}, {1, 2}, {3, 4}, {4, 6}, {1, 4}, {2, 5}}, 1 },
            { 21, {{3, 10}, {3, 19}, {1, 9}, {6, 11}, {4, 8}, {5, 12}, {5, 18}, {0, 1}, {5, 15}, {0, 16}, {0, 19}, {1, 8}, {10, 20}, {7, 12}, {12, 14}, {14, 20}, {17, 19}, {0, 6}, {2, 12}}, 2 },
            { 22, {{7, 17}, {6, 15}, {4, 6}, {8, 12}, {8, 21}, {16, 19}, {5, 6}, {3, 6}, {4, 11}, {5, 12}, {2, 7}, {2, 13}, {6, 10}, {4, 7}, {4, 16}, {5, 14}, {0, 6}, {5, 20}, {9, 18}, {1, 19}, {6, 9}}, 1 },
            { 11, {{3, 8}, {1, 8}, {8, 10}, {2, 9}, {1, 7}, {0, 2}, {5, 6}, {2, 5}, {4, 7}, {7, 8}, {2, 8}}, 1 },
            { 12, {{0, 1}, {0, 7}, {1, 2}, {5, 11}, {0, 10}, {3, 4}, {1, 5}, {3, 10}, {1, 4}, {0, 6}, {1, 7}, {5, 9}, {4, 5}, {1, 6}, {7, 11}, {6, 9}, {7, 8}, {3, 11}}, 1 },
            { 7, {{0, 1}, {2, 4}, {0, 4}, {0, 3}, {4, 5}, {5, 6}}, 1 },
            { 24, {{7, 23}, {3, 4}, {4, 9}, {12, 13}, {8, 18}, {5, 22}, {19, 21}, {2, 11}, {10, 21}, {1, 21}, {6, 11}, {16, 19}, {15, 17}, {7, 19}, {20, 22}, {5, 18}, {8, 14}, {2, 4}, {0, 4}, {9, 13}, {4, 23}, {8, 23}, {11, 13}, {8, 20}, {15, 19}, {18, 21}, {3, 5}, {4, 10}, {12, 17}, {4, 13}, {1, 4}, {11, 12}, {11, 21}, {13, 18}, {1, 19}}, 1 },
            { 19, {{2, 14}, {9, 16}, {4, 16}, {3, 14}, {2, 17}, {2, 7}, {1, 11}, {12, 13}, {10, 13}, {8, 13}, {15, 16}, {2, 18}, {13, 18}, {0, 5}, {5, 9}, {12, 18}, {6, 9}, {0, 17}}, 2 },
            { 11, {{0, 1}, {2, 4}, {3, 4}, {3, 7}, {3, 10}, {5, 7}, {2, 3}, {1, 7}, {8, 9}, {2, 6}, {1, 6}, {1, 3}}, 2 },
            { 17, {{3, 4}, {0, 2}, {5, 16}, {0, 5}, {0, 8}, {2, 5}, {0, 14}, {1, 15}, {6, 8}, {7, 13}, {3, 12}, {14, 15}, {0, 10}, {11, 16}, {1, 5}, {11, 13}, {0, 13}, {2, 16}, {15, 16}, {6, 10}, {4, 16}, {0, 9}, {11, 12}, {1, 10}}, 1 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countComponentsBFS(tc.n, tc.edges);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << tc.expected << Color::RESET << "\n"; cout << "     " << Color::RED << "Got:      " << result << Color::RESET << "\n";
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
