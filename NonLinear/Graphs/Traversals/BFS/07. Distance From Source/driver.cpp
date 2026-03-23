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
            { 6, {{0, 1}, {1, 2}, {3, 4}, {1, 5}, {1, 4}, {0, 2}, {0, 5}, {2, 5}, {3, 5}}, {0, 1, 1, 2, 2, 1} },
            { 5, {{2, 3}, {0, 3}, {1, 3}}, {0, 2, 2, 1, -1} },
            { 4, {{1, 2}, {0, 2}, {0, 3}}, {0, 2, 1, 1} },
            { 18, {{6, 12}, {7, 17}, {3, 7}, {4, 6}, {8, 12}, {9, 17}, {0, 11}, {13, 14}, {12, 15}, {0, 10}, {11, 16}, {10, 14}, {10, 17}, {2, 16}, {12, 14}, {4, 10}, {3, 8}, {5, 17}, {1, 4}, {0, 12}, {2, 9}, {1, 7}, {11, 15}}, {0, 3, 3, 3, 2, 3, 2, 3, 2, 3, 1, 1, 1, 3, 2, 2, 2, 2} },
            { 18, {{1, 12}, {7, 15}, {12, 15}, {2, 10}, {9, 12}, {10, 17}, {8, 10}, {5, 13}, {11, 12}, {6, 10}, {6, 16}, {4, 14}, {3, 12}, {0, 14}, {10, 12}, {3, 5}, {12, 14}}, {0, 3, 4, 3, 2, 4, 4, 4, 4, 3, 3, 3, 2, 5, 1, 3, 5, 4} },
            { 14, {{9, 13}, {0, 10}, {4, 13}, {5, 11}, {3, 4}, {0, 13}, {3, 7}, {6, 8}, {7, 13}, {1, 4}, {3, 13}, {6, 7}, {8, 12}, {5, 9}, {10, 12}, {1, 9}, {3, 5}}, {0, 3, -1, 2, 2, 3, 3, 2, 3, 2, 1, 4, 2, 1} },
            { 14, {{0, 1}, {1, 12}, {10, 11}, {0, 10}, {3, 4}, {2, 10}, {0, 3}, {0, 9}, {11, 12}, {0, 2}, {8, 9}, {2, 6}, {7, 12}, {9, 11}, {4, 11}, {5, 12}}, {0, 1, 1, 1, 2, 3, 2, 3, 2, 1, 1, 2, 2, -1} },
            { 5, {{0, 1}, {0, 3}, {0, 4}}, {0, 1, -1, 1, 1} },
            { 17, {{12, 13}, {8, 9}, {1, 6}, {11, 14}, {2, 5}, {1, 15}, {3, 9}, {4, 8}, {3, 6}, {3, 12}, {5, 12}, {9, 10}, {10, 11}, {0, 10}, {1, 11}, {2, 16}, {13, 16}, {15, 16}, {6, 16}, {3, 5}, {5, 11}, {8, 10}, {7, 14}}, {0, 3, 4, 3, 3, 3, 4, 4, 2, 2, 1, 2, 4, 5, 3, 4, 5} },
            { 19, {{6, 12}, {7, 17}, {4, 12}, {3, 16}, {5, 16}, {0, 5}, {8, 15}, {11, 14}, {0, 14}, {11, 17}, {3, 18}, {5, 15}, {0, 7}, {2, 10}, {10, 17}, {13, 16}, {7, 9}, {1, 17}, {15, 16}, {7, 18}, {4, 7}, {12, 14}, {9, 12}, {0, 9}, {8, 13}, {2, 9}, {11, 15}}, {0, 3, 2, 3, 2, 1, 3, 1, 3, 1, 3, 2, 2, 3, 1, 2, 2, 2, 2} },
            { 9, {{0, 7}, {3, 8}, {5, 8}, {6, 8}, {1, 8}, {6, 7}, {0, 2}, {2, 6}, {5, 6}, {4, 7}, {2, 8}}, {0, 3, 1, 3, 2, 3, 2, 1, 2} },
            { 17, {{6, 12}, {3, 16}, {5, 10}, {9, 14}, {1, 6}, {10, 12}, {10, 15}, {2, 14}, {4, 5}, {8, 14}, {9, 13}, {0, 10}, {2, 7}, {0, 13}, {7, 9}, {4, 10}, {0, 3}, {0, 9}, {2, 3}, {10, 16}, {1, 10}, {7, 11}}, {0, 2, 2, 1, 2, 2, 3, 2, 3, 1, 1, 3, 2, 1, 2, 2, 2} },
            { 18, {{2, 4}, {3, 4}, {4, 13}, {12, 16}, {8, 10}, {6, 17}, {0, 12}, {1, 17}, {4, 5}, {12, 14}, {3, 9}, {2, 12}, {5, 6}, {4, 11}, {3, 15}, {7, 8}, {2, 8}}, {0, 7, 2, 4, 3, 4, 5, 4, 3, 5, 4, 4, 1, 4, 2, 5, 2, 6} },
            { 2, {{0, 1}}, {0, 1} },
            { 8, {{2, 4}, {1, 2}, {0, 4}, {3, 4}, {2, 7}, {4, 6}, {5, 7}, {1, 4}, {0, 6}, {4, 5}, {0, 2}, {1, 3}}, {0, 2, 1, 2, 1, 2, 1, 2} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.distanceFromSource(tc.n, tc.edges);
            
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
