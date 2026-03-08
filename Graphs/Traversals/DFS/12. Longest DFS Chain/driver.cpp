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
            { 5, {{0, 1}, {0, 2}, {1, 2}, {0, 3}}, 2 },
            { 5, {{0, 1}, {0, 4}, {3, 4}, {2, 3}, {1, 3}}, 3 },
            { 21, {{16, 20}, {7, 17}, {3, 7}, {3, 10}, {14, 16}, {14, 19}, {8, 9}, {5, 16}, {1, 3}, {0, 11}, {11, 17}, {2, 17}, {3, 9}, {5, 18}, {4, 20}, {8, 11}, {8, 17}, {11, 19}, {2, 16}, {1, 14}, {1, 20}, {6, 13}, {3, 11}, {12, 17}, {4, 16}, {5, 14}, {0, 15}, {2, 6}, {1, 10}, {2, 12}}, 11 },
            { 22, {{4, 9}, {5, 7}, {5, 16}, {17, 18}, {8, 21}, {11, 20}, {2, 17}, {6, 11}, {4, 8}, {8, 14}, {10, 11}, {11, 13}, {1, 14}, {2, 19}, {7, 15}, {3, 14}, {2, 12}, {0, 21}, {2, 21}, {7, 11}}, 4 },
            { 2, {{0, 1}}, 1 },
            { 17, {{5, 16}, {1, 3}, {1, 12}, {4, 5}, {4, 11}, {3, 15}, {0, 1}, {9, 16}, {2, 4}, {1, 14}, {7, 9}, {6, 10}, {3, 11}, {4, 16}, {3, 14}, {4, 13}, {8, 10}, {0, 6}, {1, 13}, {1, 16}, {6, 9}, {7, 8}}, 11 },
            { 19, {{4, 6}, {5, 10}, {0, 5}, {8, 18}, {2, 5}, {0, 11}, {13, 17}, {4, 11}, {5, 12}, {1, 11}, {11, 13}, {6, 13}, {6, 16}, {7, 18}, {4, 7}, {3, 11}, {12, 17}, {5, 11}, {8, 16}, {9, 15}, {0, 12}, {9, 18}, {1, 13}, {1, 10}, {13, 15}, {7, 14}}, 12 },
            { 25, {{15, 21}, {4, 9}, {5, 7}, {5, 19}, {17, 21}, {9, 17}, {17, 18}, {17, 24}, {5, 22}, {2, 14}, {0, 20}, {11, 20}, {13, 17}, {6, 20}, {12, 21}, {3, 18}, {17, 20}, {2, 19}, {6, 10}, {6, 16}, {5, 23}, {8, 19}, {1, 19}}, 4 },
            { 15, {{4, 10}, {3, 4}, {4, 13}, {6, 11}, {1, 5}, {0, 3}, {12, 13}, {2, 3}, {6, 13}, {3, 6}, {1, 10}, {4, 8}, {4, 11}, {2, 5}, {6, 9}, {4, 7}, {12, 14}}, 11 },
            { 21, {{12, 16}, {4, 12}, {12, 19}, {4, 15}, {0, 2}, {9, 14}, {9, 11}, {8, 15}, {2, 11}, {1, 3}, {2, 8}, {1, 12}, {13, 14}, {6, 11}, {6, 14}, {3, 12}, {5, 18}, {0, 1}, {2, 4}, {17, 20}, {19, 20}, {1, 8}, {1, 14}, {10, 17}, {7, 9}, {7, 18}, {17, 19}, {1, 4}, {1, 13}, {2, 18}, {13, 18}}, 12 },
            { 19, {{12, 13}, {0, 5}, {8, 18}, {9, 11}, {1, 6}, {11, 14}, {2, 5}, {0, 14}, {10, 18}, {11, 17}, {10, 12}, {13, 17}, {5, 6}, {14, 18}, {5, 18}, {1, 5}, {7, 9}, {3, 11}, {5, 8}, {3, 17}, {10, 13}, {1, 4}, {10, 16}, {0, 15}, {2, 15}, {7, 14}}, 12 },
            { 20, {{4, 9}, {12, 19}, {3, 13}, {8, 18}, {2, 11}, {0, 11}, {0, 17}, {13, 17}, {16, 19}, {0, 18}, {3, 6}, {5, 9}, {3, 18}, {10, 11}, {6, 7}, {6, 13}, {6, 16}, {3, 5}, {5, 14}, {11, 18}, {13, 15}, {1, 19}}, 7 },
            { 22, {{6, 21}, {12, 16}, {4, 12}, {5, 13}, {8, 15}, {2, 5}, {10, 21}, {15, 17}, {6, 8}, {7, 19}, {0, 1}, {9, 16}, {17, 20}, {0, 19}, {16, 18}, {12, 14}, {3, 8}, {17, 19}, {1, 13}, {11, 18}, {13, 21}}, 9 },
            { 24, {{7, 20}, {12, 13}, {3, 19}, {8, 12}, {1, 6}, {2, 5}, {5, 22}, {2, 8}, {10, 15}, {2, 17}, {15, 23}, {6, 20}, {6, 14}, {15, 20}, {12, 15}, {4, 11}, {14, 21}, {0, 1}, {8, 14}, {13, 16}, {15, 16}, {18, 21}, {7, 21}, {4, 7}, {3, 8}, {4, 19}, {5, 8}, {0, 3}, {17, 19}, {5, 20}, {2, 9}, {2, 6}, {13, 18}, {15, 18}, {16, 17}, {1, 22}}, 16 },
            { 23, {{6, 15}, {6, 21}, {12, 13}, {12, 22}, {0, 2}, {4, 18}, {11, 17}, {13, 14}, {1, 18}, {7, 13}, {4, 5}, {3, 6}, {20, 22}, {8, 11}, {9, 13}, {0, 19}, {10, 17}, {1, 17}, {6, 7}, {7, 9}, {7, 12}, {4, 16}, {5, 11}, {5, 8}, {9, 12}, {0, 9}, {1, 13}, {19, 22}, {10, 19}, {0, 18}}, 10 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.longestDFSChain(tc.n, tc.edges);
            
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
