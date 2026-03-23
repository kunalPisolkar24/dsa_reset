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
            { 6, {{0, 4}, {3, 4}, {2, 3}, {0, 2}, {4, 5}, {2, 5}, {1, 3}, {3, 5}}, 2, 2 },
            { 5, {{2, 3}, {0, 4}, {1, 4}}, 0, 1 },
            { 12, {{0, 7}, {5, 11}, {3, 4}, {6, 9}, {1, 8}, {8, 10}, {5, 7}, {2, 9}, {0, 5}, {1, 10}, {1, 3}, {1, 9}, {3, 11}}, 2, 1 },
            { 4, {{0, 1}, {0, 2}, {0, 3}, {1, 3}}, 0, 1 },
            { 13, {{0, 7}, {5, 8}, {6, 9}, {2, 10}, {4, 12}, {5, 7}, {4, 5}, {1, 7}, {1, 10}, {3, 6}, {4, 11}, {1, 3}}, 0, 1 },
            { 19, {{6, 18}, {4, 9}, {12, 16}, {3, 7}, {3, 10}, {2, 11}, {11, 17}, {1, 18}, {2, 17}, {4, 5}, {3, 9}, {3, 12}, {3, 15}, {5, 12}, {0, 7}, {8, 14}, {9, 13}, {2, 10}, {2, 16}, {4, 7}, {3, 11}, {3, 14}, {1, 4}, {0, 18}, {2, 15}, {16, 17}}, 3, 7 },
            { 4, {{0, 1}, {1, 2}, {0, 3}, {0, 2}, {1, 3}}, 3, 0 },
            { 14, {{2, 4}, {3, 8}, {5, 11}, {2, 10}, {2, 13}, {0, 6}, {11, 12}, {2, 9}, {4, 5}, {6, 7}, {1, 7}, {5, 13}, {10, 12}, {8, 12}, {4, 11}, {0, 8}, {0, 11}, {2, 8}}, 0, 1 },
            { 3, {{0, 1}, {0, 2}}, 1, 2 },
            { 19, {{9, 14}, {9, 17}, {11, 17}, {2, 14}, {13, 14}, {10, 15}, {5, 6}, {4, 8}, {12, 18}, {5, 15}, {11, 16}, {10, 14}, {3, 8}, {12, 17}, {5, 8}, {5, 14}, {5, 17}, {0, 6}, {1, 7}, {2, 18}, {7, 8}}, 1, 1 },
            { 20, {{5, 7}, {3, 13}, {0, 2}, {5, 10}, {9, 17}, {1, 9}, {1, 18}, {4, 5}, {3, 9}, {14, 18}, {3, 18}, {0, 1}, {5, 15}, {9, 16}, {2, 16}, {6, 13}, {7, 12}, {3, 5}, {3, 11}, {9, 12}, {17, 19}, {8, 16}, {1, 4}, {10, 13}, {8, 13}, {7, 8}, {13, 15}, {16, 17}}, 3, 6 },
            { 4, {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}}, 1, 2 },
            { 9, {{0, 1}, {2, 4}, {1, 2}, {3, 4}, {5, 8}, {3, 7}, {0, 3}, {1, 4}, {2, 6}, {1, 6}, {0, 8}, {4, 7}, {2, 8}}, 3, 0 },
            { 7, {{2, 4}, {0, 4}, {0, 6}, {2, 3}, {2, 6}, {5, 6}}, 1, 2 },
            { 12, {{4, 10}, {5, 11}, {0, 10}, {2, 7}, {5, 8}, {2, 10}, {1, 8}, {1, 4}, {1, 7}, {8, 9}, {3, 6}, {9, 11}, {1, 6}, {0, 8}, {3, 5}, {0, 11}, {2, 8}}, 3, 3 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countNodesAtLevelK(tc.n, tc.edges, tc.k);
            
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
