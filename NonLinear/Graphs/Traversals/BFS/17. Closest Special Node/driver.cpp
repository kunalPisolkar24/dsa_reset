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
    vector<int> specialNodes;
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 5, {{0, 2}, {1, 3}, {3, 4}}, {0}, {0, -1, 1, -1, -1} },
            { 7, {{0, 4}, {4, 6}, {1, 4}, {2, 6}, {0, 5}, {3, 5}}, {0, 6}, {0, 2, 1, 2, 1, 1, 0} },
            { 16, {{6, 15}, {4, 9}, {12, 13}, {5, 7}, {4, 15}, {0, 2}, {9, 11}, {8, 15}, {1, 3}, {2, 11}, {0, 11}, {0, 1}, {8, 14}, {2, 4}, {0, 10}, {11, 13}, {7, 9}, {6, 10}, {12, 14}, {3, 5}, {8, 10}, {11, 15}, {0, 15}}, {12}, {3, 4, 3, 5, 4, 5, 4, 4, 2, 3, 3, 2, 0, 1, 1, 3} },
            { 10, {{2, 7}, {4, 9}, {3, 7}, {6, 8}, {0, 3}, {5, 7}, {6, 9}}, {1}, {-1, 0, -1, -1, -1, -1, -1, -1, -1, -1} },
            { 7, {{2, 4}, {4, 6}, {2, 3}, {2, 6}, {0, 5}, {1, 3}, {3, 5}}, {6, 0}, {0, 3, 1, 2, 1, 1, 0} },
            { 13, {{0, 1}, {4, 10}, {3, 8}, {4, 9}, {1, 11}, {6, 8}, {0, 6}, {0, 12}, {11, 12}, {7, 12}, {5, 6}, {6, 10}, {9, 11}, {0, 8}, {2, 5}, {7, 8}}, {4, 2}, {3, 3, 0, 4, 0, 1, 2, 4, 3, 1, 1, 2, 3} },
            { 12, {{0, 1}, {1, 11}, {1, 8}, {0, 9}, {8, 10}, {1, 4}, {3, 10}, {2, 9}, {6, 7}, {4, 8}, {7, 8}, {4, 11}, {5, 9}, {1, 6}, {7, 11}, {1, 9}, {8, 11}, {3, 11}}, {2, 9, 4}, {1, 1, 0, 2, 0, 1, 2, 2, 1, 0, 2, 1} },
            { 9, {{3, 8}, {0, 4}, {4, 6}, {2, 6}, {4, 8}, {0, 5}, {7, 8}}, {7, 2, 3}, {3, -1, 0, 0, 2, 4, 1, 0, 1} },
            { 20, {{12, 13}, {0, 2}, {5, 10}, {5, 19}, {1, 9}, {2, 14}, {10, 15}, {6, 8}, {5, 9}, {14, 18}, {4, 17}, {14, 15}, {1, 2}, {10, 14}, {11, 13}, {13, 16}, {7, 9}, {7, 15}, {6, 19}, {3, 5}, {4, 16}, {3, 8}, {0, 3}, {2, 18}}, {16, 15, 10, 11, 5}, {2, 2, 2, 1, 1, 0, 2, 1, 2, 1, 0, 0, 2, 1, 1, 0, 0, 2, 2, 1} },
            { 10, {{0, 7}, {2, 4}, {3, 8}, {1, 5}, {1, 4}, {4, 5}, {2, 6}, {5, 6}, {0, 5}, {5, 9}, {0, 8}, {6, 9}, {2, 8}}, {3, 6}, {2, 2, 1, 0, 2, 1, 0, 3, 1, 1} },
            { 15, {{9, 10}, {13, 14}, {0, 1}, {4, 10}, {4, 13}, {10, 14}, {3, 10}, {1, 4}, {5, 7}, {8, 13}, {2, 9}, {0, 12}, {6, 10}, {2, 12}, {9, 11}, {4, 7}, {12, 14}}, {10, 1, 14}, {1, 0, 2, 1, 1, 3, 1, 2, 2, 1, 0, 2, 1, 1, 0} },
            { 19, {{10, 15}, {8, 14}, {1, 5}, {7, 16}, {6, 14}, {12, 13}, {2, 13}, {1, 13}, {0, 15}, {3, 6}, {4, 8}, {8, 12}, {9, 11}, {12, 18}, {16, 17}, {11, 17}}, {10, 0, 7, 13, 5, 11}, {0, 1, 1, 5, 3, 0, 4, 0, 2, 1, 0, 0, 1, 0, 3, 1, 1, 1, 2} },
            { 14, {{0, 7}, {1, 2}, {5, 11}, {10, 11}, {11, 13}, {4, 6}, {9, 12}, {8, 13}, {3, 13}, {6, 13}, {1, 13}, {0, 8}}, {2, 3, 4, 9}, {3, 1, 0, 0, 0, 3, 1, 4, 2, 0, 3, 2, 1, 1} },
            { 17, {{3, 7}, {3, 13}, {10, 12}, {0, 11}, {7, 13}, {4, 14}, {3, 12}, {5, 12}, {8, 11}, {5, 15}, {0, 7}, {1, 2}, {9, 13}, {0, 4}, {11, 16}, {1, 8}, {2, 13}, {7, 9}, {9, 12}, {10, 16}, {7, 11}, {6, 9}}, {7}, {1, 3, 2, 1, 2, 3, 2, 0, 2, 1, 3, 1, 2, 1, 3, 4, 2} },
            { 16, {{3, 7}, {4, 6}, {0, 2}, {9, 14}, {7, 13}, {4, 14}, {3, 6}, {5, 9}, {14, 15}, {8, 11}, {10, 11}, {0, 10}, {1, 5}, {6, 13}, {7, 12}, {4, 7}, {4, 10}, {3, 14}, {5, 11}, {5, 8}, {1, 10}, {2, 15}, {7, 8}}, {2}, {1, 3, 0, 3, 3, 4, 4, 4, 4, 3, 2, 3, 5, 5, 2, 1} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.closestSpecialNode(tc.n, tc.edges, tc.specialNodes);
            
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
