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
    int k;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 7, {{0, 1}, {2, 4}, {3, 4}, {4, 5}, {0, 2}, {0, 5}, {3, 6}, {1, 3}, {3, 5}}, 4, 7 },
            { 6, {{2, 4}, {1, 2}, {0, 4}, {3, 4}, {2, 3}, {4, 5}, {0, 2}, {3, 5}}, 4, 6 },
            { 15, {{2, 4}, {3, 14}, {3, 4}, {1, 11}, {7, 10}, {6, 8}, {1, 8}, {0, 13}, {0, 2}, {4, 5}, {4, 8}, {8, 12}, {9, 14}, {7, 8}}, 1, 3 },
            { 20, {{3, 16}, {5, 7}, {14, 19}, {17, 18}, {1, 18}, {4, 11}, {9, 10}, {10, 11}, {15, 16}, {6, 13}, {16, 18}, {3, 11}, {14, 17}, {8, 10}, {10, 13}, {11, 12}, {2, 18}, {0, 18}, {7, 14}}, 1, 2 },
            { 20, {{7, 17}, {5, 16}, {5, 19}, {9, 11}, {2, 14}, {1, 12}, {16, 19}, {3, 12}, {14, 18}, {8, 17}, {10, 17}, {2, 13}, {6, 7}, {12, 14}, {4, 16}, {3, 17}, {5, 14}, {0, 3}, {9, 15}, {2, 15}, {7, 14}}, 3, 9 },
            { 12, {{3, 8}, {5, 11}, {0, 4}, {3, 4}, {1, 5}, {4, 9}, {0, 9}, {0, 11}, {2, 9}, {6, 7}, {4, 5}, {3, 9}, {6, 10}, {0, 5}, {3, 6}, {2, 5}, {4, 7}, {3, 5}}, 0, 1 },
            { 2, {{0, 1}}, 3, 2 },
            { 3, {{0, 1}, {1, 2}}, 1, 2 },
            { 13, {{0, 1}, {3, 8}, {6, 11}, {4, 9}, {2, 10}, {8, 10}, {2, 6}, {5, 6}, {1, 10}, {3, 12}, {4, 11}, {7, 11}, {1, 9}, {8, 11}}, 1, 2 },
            { 10, {{2, 4}, {3, 4}, {1, 5}, {3, 7}, {6, 8}, {1, 8}, {7, 9}, {2, 9}, {5, 9}, {4, 8}, {1, 6}, {0, 8}, {1, 9}, {3, 5}}, 3, 9 },
            { 9, {{0, 1}, {2, 4}, {0, 4}, {3, 4}, {5, 8}, {3, 7}, {0, 6}, {2, 3}, {0, 2}, {1, 7}, {3, 6}, {4, 7}, {7, 8}}, 4, 9 },
            { 14, {{6, 12}, {2, 8}, {5, 11}, {4, 9}, {11, 13}, {12, 13}, {1, 4}, {6, 7}, {0, 2}, {6, 13}, {3, 9}, {1, 10}, {2, 11}, {5, 12}, {3, 11}}, 2, 4 },
            { 19, {{3, 7}, {4, 12}, {5, 7}, {8, 9}, {9, 11}, {17, 18}, {2, 5}, {11, 14}, {1, 6}, {0, 11}, {1, 15}, {6, 8}, {15, 17}, {3, 9}, {14, 18}, {12, 18}, {0, 7}, {11, 16}, {2, 13}, {6, 10}, {7, 15}, {5, 17}, {8, 16}, {9, 15}, {2, 3}, {1, 7}, {2, 18}, {16, 17}}, 4, 18 },
            { 14, {{0, 1}, {0, 4}, {0, 10}, {6, 8}, {4, 6}, {2, 13}, {0, 6}, {4, 7}, {7, 9}, {0, 2}, {3, 9}, {3, 6}, {3, 12}, {5, 9}, {7, 11}, {10, 12}, {2, 11}, {2, 8}}, 0, 1 },
            { 17, {{9, 16}, {8, 14}, {10, 11}, {4, 10}, {12, 16}, {7, 16}, {3, 7}, {11, 13}, {1, 4}, {0, 2}, {5, 10}, {5, 6}, {12, 15}, {2, 8}}, 3, 4 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countNodesWithinDistanceK(tc.n, tc.edges, tc.k);
            
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
