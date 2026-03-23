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
            { 4, {{0, 1}, {1, 2}, {0, 3}, {0, 2}, {1, 3}}, {4} },
            { 7, {{2, 4}, {1, 2}, {0, 4}, {1, 5}, {0, 6}, {0, 2}, {2, 6}}, {1, 6} },
            { 21, {{7, 17}, {6, 15}, {3, 16}, {4, 15}, {3, 19}, {0, 5}, {10, 12}, {10, 18}, {1, 3}, {1, 9}, {16, 19}, {3, 15}, {5, 12}, {1, 2}, {0, 13}, {8, 20}, {2, 19}, {1, 17}, {6, 13}, {3, 11}, {4, 10}, {12, 20}, {5, 8}, {5, 14}, {8, 16}, {11, 12}, {9, 18}, {7, 8}}, {21} },
            { 21, {{3, 4}, {18, 20}, {14, 19}, {9, 11}, {17, 18}, {10, 15}, {11, 20}, {1, 15}, {6, 14}, {7, 19}, {6, 17}, {5, 9}, {12, 18}, {9, 10}, {9, 16}, {0, 7}, {9, 13}, {1, 5}, {0, 13}, {1, 14}, {13, 16}, {6, 16}, {12, 14}, {8, 13}, {0, 12}, {1, 16}, {2, 15}, {1, 19}, {16, 17}}, {2, 19} },
            { 6, {{2, 4}, {1, 2}, {3, 4}, {0, 3}, {0, 2}, {4, 5}, {0, 5}, {2, 5}, {1, 3}}, {6} },
            { 3, {{0, 1}, {0, 2}, {1, 2}}, {3} },
            { 14, {{4, 9}, {4, 12}, {3, 10}, {0, 2}, {4, 5}, {3, 6}, {5, 9}, {4, 11}, {2, 4}, {10, 11}, {0, 10}, {7, 9}, {4, 13}, {5, 8}, {1, 4}, {0, 6}, {2, 9}, {1, 13}, {6, 9}}, {14} },
            { 15, {{6, 12}, {4, 9}, {5, 7}, {9, 14}, {2, 5}, {1, 3}, {0, 11}, {2, 8}, {2, 14}, {6, 8}, {6, 14}, {5, 9}, {4, 11}, {0, 10}, {2, 7}, {1, 11}, {6, 13}, {3, 5}, {12, 14}, {1, 4}}, {15} },
            { 15, {{1, 2}, {10, 11}, {0, 6}, {0, 12}, {3, 13}, {5, 10}, {7, 9}, {10, 12}, {1, 10}, {9, 14}, {1, 3}, {2, 8}}, {1, 3, 11} },
            { 14, {{9, 10}, {6, 12}, {4, 10}, {3, 4}, {1, 5}, {5, 8}, {8, 10}, {4, 12}, {0, 6}, {6, 7}, {1, 13}, {2, 12}, {6, 10}, {3, 12}, {1, 6}, {0, 8}, {2, 11}, {3, 11}}, {14} },
            { 25, {{3, 19}, {17, 21}, {8, 21}, {16, 22}, {3, 9}, {4, 8}, {5, 9}, {3, 24}, {17, 23}, {9, 22}, {1, 20}, {11, 22}, {18, 21}, {14, 17}, {3, 20}, {0, 9}, {0, 6}, {9, 21}, {0, 12}, {2, 9}, {10, 16}, {0, 15}, {7, 11}, {13, 24}}, {25} },
            { 5, {{0, 3}, {1, 3}, {3, 4}}, {1, 4} },
            { 4, {{0, 2}, {1, 2}, {1, 3}}, {4} },
            { 2, {{0, 1}}, {2} },
            { 19, {{6, 12}, {7, 17}, {4, 6}, {12, 13}, {3, 10}, {14, 16}, {0, 2}, {8, 12}, {17, 18}, {8, 15}, {10, 18}, {1, 15}, {12, 15}, {5, 9}, {4, 11}, {9, 13}, {2, 10}, {3, 5}, {3, 11}, {5, 14}, {9, 12}, {11, 12}, {0, 12}, {0, 15}, {7, 11}}, {19} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.getComponentSizes(tc.n, tc.edges);
            
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
