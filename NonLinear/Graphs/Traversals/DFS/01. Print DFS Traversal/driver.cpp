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
            { 4, {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}}, {0, 1, 2, 3} },
            { 6, {{0, 1}, {2, 4}, {1, 2}, {3, 4}, {0, 3}, {1, 4}, {2, 3}, {4, 5}, {1, 3}}, {0, 1, 2, 3, 4, 5} },
            { 3, {{0, 1}, {0, 2}}, {0, 1, 2} },
            { 12, {{0, 1}, {4, 10}, {1, 2}, {6, 11}, {4, 9}, {3, 7}, {0, 3}, {8, 10}, {0, 9}, {5, 7}, {7, 9}, {4, 5}, {3, 9}, {5, 6}, {1, 6}}, {0, 1, 2, 6, 5, 4, 9, 3, 7, 10, 8, 11} },
            { 3, {{0, 1}, {0, 2}, {1, 2}}, {0, 1, 2} },
            { 17, {{6, 12}, {3, 13}, {5, 10}, {5, 16}, {8, 9}, {0, 8}, {6, 11}, {6, 14}, {5, 6}, {4, 8}, {3, 6}, {3, 12}, {5, 9}, {14, 15}, {8, 14}, {0, 4}, {1, 11}, {2, 10}, {15, 16}, {7, 12}, {0, 3}, {1, 4}, {10, 16}, {1, 10}, {7, 11}}, {0, 3, 6, 5, 9, 8, 4, 1, 10, 2, 16, 15, 14, 11, 7, 12, 13} },
            { 6, {{0, 1}, {0, 4}, {3, 4}, {2, 3}, {4, 5}, {2, 5}}, {0, 1, 4, 3, 2, 5} },
            { 19, {{3, 7}, {4, 6}, {5, 16}, {9, 17}, {8, 15}, {11, 14}, {2, 8}, {6, 11}, {5, 6}, {3, 12}, {1, 2}, {10, 11}, {8, 17}, {1, 5}, {2, 16}, {1, 17}, {4, 16}, {3, 8}, {3, 14}, {4, 13}, {0, 3}, {8, 10}, {8, 16}, {10, 16}, {1, 7}, {11, 18}}, {0, 3, 7, 1, 2, 8, 10, 11, 6, 4, 13, 16, 5, 14, 18, 15, 17, 9, 12} },
            { 15, {{1, 12}, {10, 11}, {4, 13}, {5, 8}, {1, 11}, {6, 14}, {0, 9}, {7, 13}, {2, 9}, {6, 13}, {5, 10}, {5, 6}, {2, 12}, {4, 14}, {3, 12}, {0, 14}, {1, 3}}, {0, 9, 2, 12, 1, 3, 11, 10, 5, 6, 13, 4, 14, 7, 8} },
            { 3, {{0, 1}, {1, 2}}, {0, 1, 2} },
            { 19, {{6, 18}, {3, 7}, {12, 13}, {4, 12}, {5, 7}, {8, 18}, {8, 15}, {2, 14}, {7, 16}, {4, 14}, {12, 15}, {0, 1}, {9, 16}, {10, 11}, {0, 10}, {0, 16}, {1, 8}, {2, 13}, {1, 17}, {6, 16}, {4, 10}, {12, 17}, {5, 17}, {8, 13}, {0, 15}, {7, 11}, {16, 17}}, {0, 1, 8, 13, 2, 14, 4, 10, 11, 7, 3, 5, 17, 12, 15, 16, 6, 18, 9} },
            { 16, {{6, 12}, {6, 15}, {4, 9}, {5, 7}, {8, 9}, {1, 3}, {2, 8}, {10, 15}, {6, 8}, {6, 14}, {3, 9}, {5, 6}, {4, 11}, {2, 7}, {1, 11}, {7, 12}, {6, 10}, {4, 10}, {5, 11}, {0, 9}, {1, 13}, {13, 15}}, {0, 9, 3, 1, 11, 4, 10, 6, 5, 7, 2, 8, 12, 14, 15, 13} },
            { 11, {{0, 7}, {4, 6}, {0, 3}, {5, 7}, {6, 7}, {1, 7}, {8, 9}, {0, 2}, {6, 10}, {4, 5}, {3, 6}, {1, 10}, {1, 3}, {1, 9}}, {0, 2, 3, 1, 7, 5, 4, 6, 10, 9, 8} },
            { 8, {{0, 7}, {2, 4}, {1, 2}, {2, 7}, {0, 5}, {3, 6}, {2, 5}, {3, 5}}, {0, 5, 2, 1, 4, 7, 3, 6} },
            { 8, {{0, 1}, {0, 7}, {3, 4}, {2, 7}, {1, 5}, {0, 3}, {4, 6}, {2, 3}, {6, 7}, {2, 6}, {4, 7}}, {0, 1, 5, 3, 2, 6, 4, 7} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.dfsTraversal(tc.n, tc.edges);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: ["; for(auto x:tc.expected) cout<<x<<","; cout<<"]" << Color::RESET << "\n";\
                cout << "     " << Color::RED << "Got:      ["; for(auto x:result) cout<<x<<","; cout<<"]" << Color::RESET << "\n";
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
