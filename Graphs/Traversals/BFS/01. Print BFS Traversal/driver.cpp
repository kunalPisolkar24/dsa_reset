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
            { 6, {{2, 4}, {1, 2}, {0, 4}, {1, 5}, {2, 3}, {0, 2}, {2, 5}}, {0, 2, 4, 1, 3, 5} },
            { 6, {{0, 1}, {1, 2}, {3, 4}, {1, 5}, {2, 3}, {4, 5}, {0, 5}, {2, 5}, {3, 5}}, {0, 1, 5, 2, 3, 4} },
            { 10, {{0, 1}, {2, 4}, {3, 4}, {3, 7}, {2, 9}, {0, 2}, {8, 9}, {1, 7}, {1, 6}, {2, 5}, {4, 7}, {3, 5}}, {0, 1, 2, 6, 7, 4, 5, 9, 3, 8} },
            { 9, {{3, 4}, {1, 5}, {6, 8}, {0, 3}, {4, 5}, {1, 7}, {2, 6}, {1, 6}, {1, 3}}, {0, 3, 1, 4, 5, 6, 7, 2, 8} },
            { 4, {{0, 2}, {1, 2}, {1, 3}}, {0, 2, 1, 3} },
            { 5, {{2, 4}, {1, 2}, {0, 4}, {1, 4}, {0, 2}}, {0, 2, 4, 1, 3} },
            { 9, {{3, 8}, {1, 2}, {5, 7}, {1, 4}, {3, 6}, {0, 8}, {7, 8}, {2, 8}}, {0, 8, 2, 3, 7, 1, 6, 5, 4} },
            { 9, {{0, 7}, {3, 8}, {1, 2}, {0, 4}, {6, 7}, {5, 6}, {3, 6}, {2, 5}, {1, 3}}, {0, 4, 7, 6, 3, 5, 1, 8, 2} },
            { 7, {{2, 4}, {0, 4}, {1, 5}, {4, 6}, {0, 6}, {2, 3}, {0, 2}, {5, 6}, {2, 5}, {3, 5}}, {0, 2, 4, 6, 3, 5, 1} },
            { 8, {{0, 7}, {2, 4}, {4, 6}, {5, 7}, {0, 6}, {4, 5}, {2, 6}, {1, 3}, {3, 5}}, {0, 6, 7, 2, 4, 5, 3, 1} },
            { 14, {{0, 1}, {2, 4}, {4, 13}, {2, 7}, {7, 10}, {2, 10}, {0, 3}, {6, 8}, {5, 7}, {0, 11}, {2, 13}, {8, 9}, {6, 10}, {7, 11}, {4, 7}, {7, 8}}, {0, 1, 3, 11, 7, 2, 4, 5, 8, 10, 13, 6, 9, 12} },
            { 17, {{2, 4}, {0, 4}, {2, 7}, {12, 15}, {13, 16}, {7, 13}, {5, 10}, {8, 9}, {6, 16}, {1, 16}, {1, 10}, {9, 14}, {13, 15}, {7, 11}, {1, 3}, {1, 9}}, {0, 4, 2, 7, 11, 13, 15, 16, 12, 1, 6, 3, 9, 10, 8, 14, 5} },
            { 18, {{12, 16}, {8, 15}, {2, 11}, {2, 14}, {13, 14}, {6, 11}, {7, 10}, {4, 14}, {5, 9}, {0, 16}, {2, 10}, {2, 16}, {1, 17}, {4, 7}, {3, 8}, {5, 14}, {8, 10}, {1, 16}, {13, 15}, {7, 11}}, {0, 16, 1, 2, 12, 17, 10, 11, 14, 7, 8, 6, 4, 5, 13, 3, 15, 9} },
            { 10, {{0, 1}, {4, 9}, {0, 3}, {7, 9}, {2, 9}, {8, 9}, {3, 9}, {2, 6}, {3, 5}}, {0, 1, 3, 5, 9, 2, 4, 7, 8, 6} },
            { 16, {{6, 12}, {0, 5}, {2, 5}, {1, 3}, {1, 12}, {7, 13}, {3, 6}, {12, 15}, {3, 12}, {14, 15}, {8, 14}, {2, 7}, {10, 14}, {11, 13}, {1, 14}, {7, 9}, {4, 7}, {12, 14}, {3, 14}, {0, 9}, {1, 4}, {11, 15}}, {0, 5, 9, 2, 7, 4, 13, 1, 11, 3, 12, 14, 15, 6, 8, 10} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.bfsTraversal(tc.n, tc.edges);
            
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
