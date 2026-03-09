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
            { 6, {{0, 1}, {2, 4}, {1, 5}, {4, 5}, {1, 3}, {3, 5}}, 6 },
            { 5, {{2, 4}, {1, 2}, {3, 4}, {0, 2}}, 5 },
            { 21, {{6, 18}, {10, 12}, {2, 8}, {10, 15}, {6, 14}, {12, 15}, {2, 4}, {9, 13}, {0, 13}, {1, 14}, {2, 13}, {12, 14}, {3, 11}, {4, 16}, {3, 14}, {5, 11}, {12, 20}, {14, 17}, {0, 3}, {17, 19}, {8, 19}, {1, 10}, {11, 18}, {16, 17}, {7, 14}}, 21 },
            { 17, {{3, 14}, {5, 8}, {12, 16}, {4, 6}, {8, 10}, {6, 14}, {2, 13}, {0, 3}, {11, 15}, {7, 12}, {1, 6}, {13, 15}, {6, 9}, {5, 12}}, 7 },
            { 11, {{0, 7}, {0, 4}, {3, 7}, {1, 4}, {7, 9}, {0, 2}, {8, 9}, {1, 7}, {5, 6}, {0, 5}, {3, 5}}, 10 },
            { 19, {{0, 1}, {9, 16}, {4, 16}, {8, 17}, {5, 8}, {8, 16}, {14, 16}, {9, 15}, {10, 13}, {10, 16}, {3, 6}, {2, 18}, {8, 12}, {4, 11}, {0, 8}, {6, 9}, {7, 8}, {2, 8}}, 19 },
            { 15, {{2, 14}, {13, 14}, {2, 4}, {10, 11}, {5, 11}, {2, 7}, {2, 10}, {5, 7}, {0, 6}, {0, 12}, {6, 7}, {5, 6}, {1, 6}, {6, 9}, {8, 11}, {3, 11}}, 15 },
            { 19, {{7, 17}, {12, 16}, {4, 6}, {5, 13}, {9, 11}, {2, 5}, {1, 3}, {0, 17}, {2, 14}, {4, 5}, {4, 14}, {9, 16}, {2, 10}, {13, 16}, {6, 13}, {16, 18}, {7, 15}, {4, 10}, {5, 14}, {8, 13}, {0, 12}, {1, 7}, {11, 12}, {1, 10}}, 19 },
            { 14, {{12, 13}, {3, 10}, {0, 2}, {9, 11}, {0, 8}, {6, 8}, {7, 13}, {5, 6}, {8, 11}, {0, 7}, {9, 13}, {0, 13}, {2, 10}, {7, 12}, {4, 7}, {3, 8}, {10, 13}, {11, 12}, {1, 13}}, 14 },
            { 20, {{4, 10}, {2, 17}, {6, 15}, {11, 16}, {4, 9}, {11, 19}, {0, 19}, {4, 12}, {1, 4}, {5, 7}, {4, 15}, {8, 13}, {4, 5}, {1, 13}, {12, 14}, {15, 19}, {2, 12}, {3, 5}}, 19 },
            { 17, {{4, 16}, {10, 11}, {2, 7}, {10, 14}, {12, 16}, {1, 4}, {0, 6}, {2, 3}, {9, 15}, {10, 16}, {4, 5}, {3, 9}, {8, 13}, {6, 16}, {3, 12}}, 15 },
            { 16, {{4, 6}, {5, 7}, {3, 13}, {0, 5}, {8, 12}, {9, 11}, {0, 8}, {11, 14}, {2, 14}, {1, 12}, {4, 14}, {4, 11}, {9, 10}, {11, 13}, {3, 11}, {3, 14}, {5, 11}, {9, 12}, {11, 12}, {2, 9}, {0, 15}, {6, 9}}, 16 },
            { 3, {{0, 1}, {0, 2}}, 3 },
            { 23, {{4, 21}, {5, 16}, {8, 12}, {17, 18}, {0, 14}, {9, 20}, {7, 13}, {7, 22}, {5, 6}, {3, 6}, {5, 9}, {14, 21}, {1, 2}, {10, 20}, {13, 15}, {7, 21}, {11, 12}, {2, 12}, {10, 19}, {2, 21}, {15, 18}}, 15 },
            { 19, {{6, 12}, {4, 10}, {1, 2}, {0, 16}, {1, 9}, {6, 14}, {10, 13}, {1, 17}, {11, 12}, {6, 13}, {7, 12}, {1, 10}, {1, 16}, {2, 15}, {0, 8}, {1, 3}, {5, 12}, {10, 18}}, 19 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.largestComponentSize(tc.n, tc.edges);
            
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
