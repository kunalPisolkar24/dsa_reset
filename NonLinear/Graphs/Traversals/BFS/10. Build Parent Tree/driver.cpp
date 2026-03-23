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
            { 7, {{1, 2}, {0, 4}, {0, 3}, {0, 2}, {3, 6}, {3, 5}}, {-1, 2, 0, 0, 0, 3, 3} },
            { 7, {{0, 4}, {4, 6}, {3, 6}, {1, 6}, {2, 5}, {3, 5}}, {-1, 6, 5, 6, 0, 3, 4} },
            { 16, {{5, 15}, {4, 10}, {3, 14}, {5, 11}, {9, 13}, {0, 10}, {6, 8}, {12, 13}, {7, 13}, {1, 4}, {5, 10}, {6, 13}, {7, 12}, {5, 6}, {2, 11}, {4, 7}, {0, 11}}, {-1, 4, 11, -1, 10, 10, 5, 4, 6, 13, 0, 0, 7, 7, -1, 5} },
            { 18, {{4, 16}, {10, 11}, {7, 17}, {0, 16}, {14, 17}, {3, 17}, {15, 17}, {2, 16}, {5, 13}, {8, 13}, {8, 12}, {5, 9}, {6, 16}, {1, 16}, {1, 6}, {3, 15}, {11, 17}}, {-1, 16, 16, -1, 16, -1, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1} },
            { 2, {{0, 1}}, {-1, 0} },
            { 12, {{0, 1}, {4, 10}, {9, 10}, {10, 11}, {0, 10}, {1, 5}, {4, 6}, {1, 4}, {6, 7}, {1, 7}, {8, 9}, {4, 8}, {7, 8}, {3, 5}, {2, 8}}, {-1, 0, 8, 5, 1, 1, 4, 1, 4, 10, 0, 10} },
            { 12, {{0, 1}, {10, 11}, {5, 11}, {6, 11}, {7, 10}, {4, 6}, {0, 11}, {2, 9}, {1, 7}, {9, 11}, {7, 8}, {3, 11}}, {-1, 0, 9, 11, 6, 11, 11, 1, 7, 11, 11, 0} },
            { 7, {{0, 4}, {1, 5}, {0, 3}, {4, 6}, {0, 6}, {2, 3}, {2, 6}, {0, 5}}, {-1, 5, 3, 0, 0, 0, 0} },
            { 20, {{3, 10}, {0, 14}, {1, 9}, {1, 15}, {13, 17}, {6, 17}, {14, 18}, {0, 1}, {5, 15}, {8, 14}, {0, 16}, {1, 11}, {1, 8}, {7, 9}, {15, 19}, {3, 14}, {0, 3}, {0, 12}, {2, 9}, {2, 12}, {1, 10}, {2, 18}, {7, 11}}, {-1, 0, 12, 0, -1, 15, -1, 9, 1, 1, 1, 1, 0, -1, 0, 1, 0, -1, 14, 15} },
            { 3, {{0, 1}, {0, 2}, {1, 2}}, {-1, 0, 0} },
            { 2, {{0, 1}}, {-1, 0} },
            { 20, {{7, 17}, {6, 15}, {4, 6}, {3, 13}, {9, 14}, {9, 17}, {1, 3}, {13, 14}, {12, 15}, {3, 18}, {5, 15}, {8, 17}, {0, 19}, {1, 17}, {6, 16}, {3, 11}, {17, 19}, {9, 15}, {10, 19}, {2, 15}, {15, 18}}, {-1, 17, 15, 1, 6, 15, 15, 17, 17, 17, 19, 3, 15, 3, 9, 9, 6, 19, 3, 0} },
            { 10, {{0, 1}, {1, 2}, {0, 4}, {3, 4}, {5, 8}, {2, 3}, {0, 2}, {3, 9}, {0, 5}, {1, 6}, {6, 9}, {7, 8}}, {-1, 0, 0, 2, 0, 0, 1, 8, 5, 6} },
            { 7, {{2, 4}, {1, 2}, {3, 4}, {1, 5}, {4, 6}, {0, 6}, {0, 2}, {5, 6}, {1, 6}, {1, 3}}, {-1, 2, 0, 1, 2, 6, 0} },
            { 19, {{4, 9}, {3, 10}, {8, 9}, {9, 14}, {8, 18}, {1, 6}, {1, 12}, {7, 13}, {3, 9}, {5, 18}, {2, 10}, {2, 16}, {7, 9}, {15, 16}, {3, 11}, {4, 10}, {12, 17}, {14, 17}, {5, 17}, {8, 16}, {10, 13}, {9, 15}, {1, 7}, {2, 6}}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.buildParentTree(tc.n, tc.edges);
            
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
