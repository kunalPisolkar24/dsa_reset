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
            { 7, {{3, 4}, {1, 5}, {2, 3}, {4, 5}, {0, 2}, {2, 6}, {2, 5}}, 7 },
            { 6, {{0, 1}, {2, 4}, {1, 2}, {0, 3}, {1, 4}, {2, 3}, {0, 2}, {0, 5}, {1, 3}}, 6 },
            { 6, {{0, 1}, {0, 4}, {1, 4}, {2, 3}, {0, 2}, {0, 5}, {3, 5}}, 6 },
            { 4, {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}}, 4 },
            { 7, {{0, 1}, {4, 6}, {1, 4}, {4, 5}, {5, 6}, {1, 6}}, 5 },
            { 19, {{6, 18}, {3, 10}, {5, 13}, {5, 10}, {8, 12}, {17, 18}, {1, 9}, {2, 8}, {1, 18}, {3, 18}, {12, 18}, {5, 15}, {0, 4}, {1, 11}, {13, 18}, {16, 18}, {7, 15}, {4, 7}, {12, 14}, {3, 11}, {1, 4}, {2, 3}, {1, 16}}, 19 },
            { 8, {{2, 4}, {0, 4}, {4, 6}, {5, 7}, {1, 7}, {4, 7}}, 7 },
            { 24, {{5, 19}, {11, 14}, {2, 8}, {0, 20}, {2, 17}, {12, 15}, {3, 21}, {10, 11}, {1, 11}, {11, 13}, {19, 20}, {2, 16}, {10, 23}, {11, 22}, {2, 19}, {7, 9}, {7, 12}, {6, 10}, {15, 22}, {4, 16}, {5, 23}, {17, 22}, {2, 18}}, 22 },
            { 12, {{4, 10}, {0, 7}, {10, 11}, {0, 10}, {1, 11}, {3, 7}, {0, 3}, {4, 6}, {8, 10}, {1, 4}, {7, 9}, {4, 5}, {0, 2}, {4, 8}, {0, 11}}, 12 },
            { 9, {{2, 4}, {5, 8}, {6, 8}, {1, 6}, {0, 8}, {1, 3}, {2, 8}}, 8 },
            { 18, {{9, 16}, {1, 2}, {2, 17}, {5, 11}, {7, 14}, {0, 13}, {0, 12}, {6, 13}, {0, 2}, {6, 10}, {7, 8}, {9, 11}, {4, 11}, {14, 15}, {4, 7}, {0, 11}, {3, 11}}, 18 },
            { 6, {{1, 2}, {0, 3}, {1, 4}, {1, 3}, {3, 5}}, 6 },
            { 21, {{6, 12}, {4, 12}, {4, 18}, {0, 5}, {9, 17}, {0, 17}, {2, 20}, {6, 14}, {4, 5}, {4, 8}, {3, 6}, {5, 9}, {8, 11}, {17, 20}, {2, 16}, {1, 20}, {16, 18}, {7, 18}, {3, 11}, {4, 16}, {4, 13}, {12, 20}, {5, 8}, {8, 10}, {8, 19}, {1, 16}, {13, 15}}, 21 },
            { 25, {{15, 21}, {3, 10}, {5, 19}, {17, 21}, {10, 12}, {8, 24}, {1, 12}, {9, 23}, {0, 20}, {11, 23}, {13, 17}, {1, 21}, {15, 17}, {7, 19}, {5, 9}, {0, 4}, {10, 14}, {2, 10}, {10, 17}, {10, 20}, {6, 13}, {11, 24}, {7, 24}, {3, 5}, {12, 17}, {12, 23}, {20, 24}, {5, 8}, {0, 12}, {2, 9}, {10, 16}, {2, 15}, {10, 22}, {7, 11}, {15, 18}, {13, 24}}, 25 },
            { 22, {{7, 17}, {7, 20}, {4, 6}, {3, 10}, {0, 2}, {1, 6}, {9, 17}, {0, 8}, {10, 21}, {2, 20}, {15, 20}, {3, 12}, {14, 18}, {3, 18}, {3, 21}, {5, 18}, {1, 2}, {11, 16}, {8, 20}, {13, 16}, {16, 18}, {7, 15}, {20, 21}, {3, 8}, {4, 19}, {3, 17}, {11, 12}, {2, 9}, {2, 3}, {0, 21}, {10, 19}, {13, 18}, {11, 18}}, 22 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.largestComponent(tc.n, tc.edges);
            
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
