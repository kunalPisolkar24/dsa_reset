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
            { 4, {{0, 1}, {2, 3}, {1, 2}, {1, 3}}, 2 },
            { 4, {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}}, 3 },
            { 18, {{4, 9}, {3, 16}, {3, 13}, {0, 2}, {5, 16}, {0, 5}, {9, 17}, {1, 3}, {6, 11}, {7, 16}, {12, 15}, {4, 11}, {8, 11}, {0, 1}, {2, 4}, {0, 10}, {12, 14}, {3, 11}, {4, 16}, {10, 16}, {2, 6}, {13, 15}, {16, 17}}, 14 },
            { 7, {{0, 1}, {3, 4}, {1, 4}, {4, 5}, {2, 6}, {0, 5}, {2, 5}, {1, 3}}, 6 },
            { 5, {{0, 1}, {2, 4}, {1, 2}, {0, 4}, {2, 3}, {0, 2}}, 3 },
            { 16, {{3, 8}, {0, 10}, {10, 14}, {4, 9}, {7, 10}, {1, 14}, {4, 12}, {10, 13}, {2, 13}, {8, 9}, {0, 15}, {9, 11}, {6, 9}}, 1 },
            { 18, {{3, 8}, {2, 7}, {0, 16}, {5, 14}, {15, 17}, {6, 14}, {5, 17}, {7, 13}, {10, 16}, {6, 10}, {3, 6}, {4, 14}, {1, 10}, {6, 9}, {11, 17}}, 11 },
            { 15, {{3, 14}, {0, 4}, {0, 10}, {4, 13}, {6, 11}, {1, 11}, {3, 7}, {4, 9}, {2, 10}, {8, 13}, {3, 13}, {1, 13}, {3, 6}, {9, 14}, {8, 12}, {3, 12}, {5, 9}}, 6 },
            { 16, {{9, 11}, {8, 15}, {6, 11}, {4, 5}, {12, 15}, {4, 11}, {5, 12}, {9, 10}, {0, 7}, {1, 5}, {6, 10}, {3, 5}, {3, 14}, {5, 11}, {1, 4}, {9, 15}, {1, 7}, {11, 15}, {2, 6}, {13, 15}, {7, 14}}, 2 },
            { 12, {{3, 4}, {1, 11}, {2, 10}, {8, 10}, {2, 11}, {1, 4}, {0, 6}, {5, 10}, {2, 6}, {6, 10}, {9, 11}, {6, 9}, {4, 7}}, 3 },
            { 12, {{0, 4}, {2, 8}, {0, 3}, {5, 7}, {7, 9}, {1, 7}, {8, 9}, {0, 2}, {1, 10}, {3, 6}, {4, 8}, {7, 8}, {3, 11}}, 10 },
            { 14, {{1, 3}, {2, 4}, {0, 10}, {3, 4}, {7, 10}, {4, 6}, {3, 10}, {10, 13}, {11, 12}, {2, 9}, {8, 9}, {3, 9}, {5, 6}, {5, 9}, {1, 13}, {9, 11}, {10, 12}, {8, 11}}, 2 },
            { 18, {{0, 1}, {9, 16}, {6, 12}, {10, 15}, {4, 13}, {6, 11}, {1, 14}, {14, 16}, {1, 17}, {6, 7}, {8, 13}, {3, 9}, {2, 15}, {5, 12}, {2, 8}}, 3 },
            { 20, {{12, 16}, {4, 18}, {1, 3}, {10, 15}, {1, 15}, {6, 8}, {7, 13}, {18, 19}, {0, 18}, {14, 15}, {8, 14}, {10, 14}, {1, 5}, {11, 19}, {2, 10}, {6, 16}, {5, 11}, {4, 19}, {14, 17}, {2, 9}, {1, 7}, {2, 6}, {2, 12}, {0, 15}, {13, 18}, {11, 18}, {2, 15}, {1, 10}, {15, 18}}, 16 },
            { 18, {{12, 16}, {8, 9}, {0, 11}, {2, 14}, {1, 12}, {1, 15}, {13, 17}, {6, 17}, {3, 9}, {4, 14}, {3, 6}, {12, 15}, {4, 17}, {14, 15}, {8, 14}, {0, 4}, {0, 10}, {0, 16}, {9, 13}, {2, 16}, {1, 17}, {6, 7}, {3, 11}, {5, 11}, {8, 10}, {1, 7}, {2, 15}}, 7 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.farthestNode(tc.n, tc.edges);
            
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
