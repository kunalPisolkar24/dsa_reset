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
            { 4, {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}}, {0, 1, 3} },
            { 5, {{2, 4}, {1, 2}, {0, 4}, {0, 3}, {1, 4}, {0, 2}, {1, 3}}, {0, 2, 1} },
            { 6, {{0, 4}, {3, 4}, {0, 3}, {1, 4}, {2, 3}, {2, 5}, {1, 3}, {3, 5}}, {0, 3, 1} },
            { 9, {{0, 7}, {3, 8}, {1, 5}, {1, 4}, {6, 7}, {2, 6}}, {0, 7, 6, 2} },
            { 14, {{9, 10}, {3, 8}, {5, 11}, {6, 8}, {0, 9}, {10, 13}, {7, 11}, {1, 4}, {2, 13}, {1, 7}, {8, 9}, {5, 10}, {5, 6}, {7, 12}, {3, 6}, {9, 11}, {2, 5}, {10, 12}}, {0, 9, 8, 3, 2, 4} },
            { 3, {{0, 1}, {0, 2}, {1, 2}}, {0, 1} },
            { 6, {{2, 4}, {3, 4}, {1, 5}, {0, 2}, {0, 5}, {1, 3}, {3, 5}}, {0, 2, 4} },
            { 16, {{6, 12}, {13, 14}, {2, 4}, {0, 1}, {5, 14}, {1, 8}, {0, 3}, {5, 7}, {2, 9}, {2, 12}, {12, 15}, {8, 11}, {7, 8}}, {0, 1, 8, 7, 5, 14, 13} },
            { 14, {{1, 12}, {2, 7}, {5, 8}, {1, 11}, {7, 10}, {2, 10}, {1, 8}, {4, 6}, {0, 3}, {5, 10}, {1, 13}, {0, 2}, {4, 8}, {3, 5}}, {0, 2, 7, 8, 1, 11} },
            { 21, {{0, 5}, {8, 12}, {8, 18}, {2, 11}, {9, 20}, {11, 17}, {1, 18}, {13, 17}, {15, 17}, {15, 20}, {4, 5}, {3, 12}, {5, 15}, {8, 20}, {13, 16}, {10, 20}, {15, 16}, {15, 19}, {3, 8}, {5, 14}, {2, 6}, {7, 8}}, {0, 5, 4, 16, 13, 2, 6} },
            { 18, {{13, 14}, {2, 4}, {6, 11}, {0, 3}, {5, 17}, {3, 10}, {14, 15}, {4, 6}, {2, 3}, {3, 13}, {10, 16}, {3, 9}, {2, 12}, {3, 12}, {0, 8}, {2, 5}, {1, 3}, {7, 14}}, {0, 3, 1, 4, 6, 11} },
            { 2, {{0, 1}}, {0, 1} },
            { 10, {{3, 7}, {1, 9}, {4, 6}, {0, 9}, {2, 9}, {2, 5}, {4, 7}, {7, 8}}, {0, 9, 1, 5} },
            { 10, {{3, 8}, {2, 4}, {0, 4}, {1, 5}, {5, 8}, {0, 9}, {2, 3}, {7, 9}, {2, 6}, {4, 8}, {0, 5}, {2, 5}, {3, 5}, {7, 8}}, {0, 4, 2, 6} },
            { 2, {{0, 1}}, {0, 1} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.firstNodePerLevel(tc.n, tc.edges);
            
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
