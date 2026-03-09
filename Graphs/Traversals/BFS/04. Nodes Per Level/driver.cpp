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
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 7, {{2, 4}, {0, 4}, {0, 2}, {1, 6}, {2, 5}, {1, 3}, {3, 5}}, {1, 2, 1, 1, 1, 1} },
            { 7, {{0, 4}, {1, 4}, {0, 6}, {2, 3}, {2, 6}, {1, 6}, {1, 3}, {3, 5}}, {1, 2, 2, 1, 1} },
            { 11, {{0, 1}, {3, 8}, {7, 10}, {1, 4}, {2, 6}, {5, 6}, {6, 9}, {7, 8}}, {1, 1, 1} },
            { 23, {{6, 21}, {4, 18}, {8, 15}, {1, 3}, {9, 20}, {13, 17}, {13, 20}, {6, 14}, {15, 20}, {7, 19}, {0, 7}, {1, 2}, {11, 16}, {10, 14}, {0, 19}, {11, 22}, {10, 20}, {1, 17}, {7, 12}, {15, 19}, {16, 18}, {15, 22}, {18, 21}, {3, 14}, {5, 11}, {1, 4}, {0, 6}, {0, 21}, {2, 21}}, {1, 4, 5, 8, 4, 1} },
            { 9, {{3, 8}, {0, 3}, {5, 7}, {0, 2}, {1, 7}, {5, 6}, {4, 8}, {1, 6}, {4, 7}, {2, 8}}, {1, 2, 1, 1, 1, 2, 1} },
            { 24, {{14, 22}, {17, 21}, {1, 3}, {9, 20}, {13, 14}, {2, 17}, {16, 22}, {4, 8}, {4, 17}, {10, 11}, {19, 23}, {9, 22}, {11, 19}, {6, 7}, {7, 12}, {16, 18}, {0, 3}, {5, 17}, {11, 15}, {19, 22}, {1, 22}}, {1, 1, 1, 1, 4, 5, 2} },
            { 6, {{1, 2}, {1, 4}, {0, 2}, {2, 5}, {1, 3}}, {1, 1, 2, 2} },
            { 18, {{3, 13}, {0, 8}, {1, 9}, {7, 10}, {7, 16}, {6, 17}, {3, 9}, {3, 12}, {0, 4}, {2, 16}, {1, 14}, {7, 9}, {6, 7}, {3, 11}, {5, 17}, {1, 7}, {11, 15}, {1, 10}, {6, 9}}, {1, 2} },
            { 6, {{2, 4}, {1, 5}, {1, 4}, {2, 3}, {0, 2}, {2, 5}, {3, 5}}, {1, 1, 3, 1} },
            { 20, {{3, 13}, {9, 11}, {17, 18}, {10, 12}, {1, 9}, {0, 11}, {10, 15}, {1, 15}, {6, 11}, {5, 6}, {8, 11}, {0, 10}, {11, 16}, {10, 14}, {0, 13}, {11, 13}, {13, 16}, {2, 19}, {13, 19}, {7, 12}, {6, 16}, {4, 10}, {12, 17}, {5, 14}, {0, 3}, {1, 4}, {1, 10}, {13, 18}, {2, 15}}, {1, 4, 11, 4} },
            { 8, {{0, 1}, {0, 7}, {1, 2}, {3, 4}, {2, 7}, {2, 3}, {4, 5}, {1, 7}, {0, 2}, {5, 6}}, {1, 3, 1, 1, 1, 1} },
            { 7, {{1, 5}, {2, 3}, {0, 2}, {4, 5}, {2, 6}, {0, 5}}, {1, 2, 4} },
            { 7, {{0, 1}, {1, 2}, {4, 6}, {2, 3}, {0, 2}, {2, 6}, {5, 6}, {3, 6}, {1, 6}, {2, 5}}, {1, 2, 3, 1} },
            { 23, {{4, 6}, {3, 22}, {1, 6}, {9, 17}, {0, 17}, {11, 17}, {13, 14}, {11, 20}, {2, 20}, {13, 20}, {18, 22}, {4, 11}, {12, 18}, {14, 21}, {8, 11}, {10, 11}, {2, 7}, {13, 19}, {15, 16}, {6, 13}, {5, 8}, {3, 20}, {11, 12}, {5, 20}, {9, 21}, {10, 19}, {16, 17}}, {1, 1, 3, 7, 8, 3} },
            { 18, {{7, 17}, {8, 15}, {1, 9}, {0, 11}, {10, 15}, {2, 17}, {1, 15}, {6, 14}, {7, 13}, {5, 6}, {12, 15}, {3, 6}, {1, 2}, {0, 4}, {0, 10}, {1, 5}, {7, 9}, {15, 16}, {7, 11}, {6, 9}}, {1, 3, 2, 7, 3, 2} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.nodesPerLevel(tc.n, tc.edges);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: ["; for(auto x:tc.expected) cout<<x<<","; cout<<"]" << Color::RESET << "\n"; cout << "     " << Color::RED << "Got:      ["; for(auto x:result) cout<<x<<","; cout<<"]" << Color::RESET << "\n";
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
