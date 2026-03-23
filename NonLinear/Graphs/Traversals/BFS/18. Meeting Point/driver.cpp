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
    vector<int> group1;
    vector<int> group2;
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 6, {{2, 4}, {2, 5}, {1, 3}, {1, 4}}, {3}, {1}, {1, 3} },
            { 6, {{0, 1}, {2, 4}, {0, 4}, {2, 3}, {4, 5}, {0, 2}, {3, 5}}, {2, 3}, {1, 5}, {0, 3, 4, 5} },
            { 9, {{3, 8}, {1, 2}, {1, 5}, {6, 8}, {5, 7}, {0, 6}, {2, 3}, {4, 8}, {1, 3}, {3, 5}}, {5}, {0, 8}, {3} },
            { 16, {{6, 15}, {5, 7}, {0, 8}, {11, 14}, {2, 11}, {0, 11}, {10, 15}, {7, 10}, {7, 13}, {3, 9}, {4, 8}, {3, 6}, {4, 14}, {0, 4}, {1, 5}, {1, 11}, {1, 8}, {7, 9}, {7, 12}, {7, 15}, {3, 5}, {0, 9}, {2, 3}, {7, 14}}, {10}, {2, 4, 13, 11}, {7} },
            { 8, {{2, 7}, {1, 5}, {4, 6}, {0, 3}, {0, 2}, {2, 6}, {0, 5}, {1, 6}}, {1, 0}, {4}, {6} },
            { 17, {{4, 6}, {12, 13}, {4, 12}, {8, 15}, {1, 3}, {0, 11}, {2, 14}, {7, 10}, {4, 14}, {3, 12}, {14, 15}, {5, 12}, {11, 13}, {1, 8}, {2, 13}, {7, 9}, {4, 7}, {5, 14}, {8, 16}, {2, 12}, {1, 10}, {7, 11}, {7, 14}}, {8}, {9, 3, 16, 0}, {1, 8, 16} },
            { 13, {{1, 12}, {1, 2}, {0, 4}, {6, 9}, {1, 11}, {3, 7}, {1, 5}, {4, 12}, {2, 11}, {5, 10}, {10, 12}, {1, 10}, {8, 12}, {9, 11}, {4, 11}, {1, 3}, {1, 9}, {8, 11}}, {4, 0}, {5, 12, 11, 8, 10}, {4, 11, 12} },
            { 20, {{6, 18}, {12, 13}, {12, 19}, {3, 10}, {5, 19}, {8, 15}, {11, 14}, {2, 11}, {13, 14}, {7, 16}, {4, 5}, {14, 15}, {5, 18}, {5, 15}, {0, 7}, {2, 4}, {9, 13}, {0, 10}, {11, 16}, {10, 17}, {1, 8}, {13, 19}, {7, 12}, {6, 10}, {5, 17}, {8, 16}, {2, 6}, {1, 10}}, {4, 10, 17, 0, 1}, {14, 6, 2}, {2, 4, 6, 10} },
            { 17, {{9, 10}, {0, 7}, {3, 14}, {11, 13}, {5, 7}, {1, 4}, {2, 3}, {3, 13}, {2, 6}, {7, 12}, {2, 15}, {8, 15}, {1, 9}, {0, 11}}, {9, 4, 2}, {15, 0, 12, 14, 1, 6, 3}, {1, 2, 3, 4, 6, 9, 15} },
            { 16, {{4, 12}, {5, 7}, {4, 15}, {0, 8}, {8, 15}, {11, 14}, {2, 11}, {2, 5}, {12, 15}, {5, 9}, {3, 15}, {8, 11}, {0, 1}, {8, 14}, {9, 13}, {1, 11}, {11, 13}, {2, 10}, {6, 7}, {4, 7}, {11, 12}, {13, 15}, {7, 8}}, {7, 2, 13, 10, 1}, {5, 9, 14}, {2, 5, 7, 8, 9, 11, 13} },
            { 9, {{0, 1}, {0, 7}, {0, 4}, {3, 4}, {1, 5}, {4, 6}, {1, 4}, {0, 6}, {6, 7}, {0, 2}, {4, 8}, {0, 8}, {4, 7}}, {5, 0}, {2, 7, 1}, {0, 1, 2, 4, 5, 6, 7} },
            { 16, {{6, 12}, {6, 15}, {4, 9}, {4, 12}, {12, 13}, {5, 13}, {8, 9}, {9, 14}, {8, 12}, {4, 5}, {4, 8}, {1, 2}, {0, 4}, {2, 13}, {7, 12}, {3, 5}, {4, 10}, {8, 10}, {9, 15}, {11, 12}, {1, 13}, {0, 15}, {13, 15}, {7, 14}}, {0, 7, 9, 8}, {2, 14}, {7, 9, 14} },
            { 10, {{3, 4}, {1, 5}, {4, 6}, {0, 9}, {1, 4}, {2, 3}, {2, 9}, {4, 8}, {3, 6}, {2, 5}, {6, 9}, {4, 7}}, {4, 1, 8}, {6, 3}, {3, 4, 6} },
            { 7, {{1, 4}, {0, 6}, {4, 5}, {5, 6}, {3, 6}}, {5}, {4}, {4, 5} },
            { 8, {{2, 4}, {1, 4}, {5, 7}, {2, 6}, {0, 5}, {3, 6}, {1, 3}}, {4, 0}, {5, 7, 2}, {0, 2, 4, 5} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.meetingPoint(tc.n, tc.edges, tc.group1, tc.group2);
            
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
