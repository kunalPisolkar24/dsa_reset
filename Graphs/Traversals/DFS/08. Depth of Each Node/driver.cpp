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
            { 7, {{1, 2}, {3, 4}, {4, 6}, {1, 4}, {0, 5}, {3, 6}, {1, 3}}, {0, 0, 1, 1, 2, 1, 3} },
            { 4, {{0, 1}, {1, 2}, {0, 3}, {2, 3}, {0, 2}, {1, 3}}, {0, 1, 2, 3} },
            { 18, {{2, 14}, {13, 14}, {8, 14}, {3, 14}, {1, 5}, {10, 14}, {1, 14}, {14, 16}, {6, 17}, {1, 7}, {6, 13}, {7, 12}, {4, 14}, {7, 15}, {9, 17}, {0, 14}, {0, 11}}, {0, 2, 2, 2, 2, 3, 3, 3, 2, 5, 2, 1, 4, 2, 1, 4, 2, 4} },
            { 7, {{2, 4}, {0, 4}, {1, 5}, {1, 4}, {2, 3}, {3, 6}}, {0, 2, 2, 3, 1, 3, 4} },
            { 8, {{0, 1}, {2, 4}, {4, 6}, {0, 6}, {5, 6}, {4, 7}, {3, 5}}, {0, 1, 3, 3, 2, 2, 1, 3} },
            { 17, {{10, 15}, {0, 10}, {10, 14}, {11, 13}, {6, 8}, {0, 3}, {12, 13}, {2, 10}, {12, 16}, {0, 2}, {5, 9}, {7, 12}, {9, 14}, {4, 8}, {7, 15}, {9, 11}, {1, 9}, {8, 11}}, {0, 5, 1, 1, 7, 5, 7, 8, 6, 4, 2, 5, 7, 6, 3, 9, 8} },
            { 6, {{2, 4}, {0, 4}, {1, 4}, {4, 5}, {0, 2}, {1, 3}}, {0, 3, 1, 4, 2, 3} },
            { 11, {{0, 1}, {4, 10}, {3, 4}, {4, 9}, {2, 10}, {3, 10}, {1, 4}, {2, 3}, {2, 9}, {0, 2}, {7, 9}, {5, 6}, {2, 5}, {7, 8}}, {0, 1, 4, 3, 2, 5, 6, 6, 7, 5, 5} },
            { 10, {{3, 8}, {2, 7}, {1, 4}, {0, 6}, {2, 9}, {5, 6}, {0, 5}, {1, 6}, {0, 8}, {3, 5}}, {0, 3, 0, 2, 4, 1, 2, 1, 3, 1} },
            { 4, {{0, 1}, {1, 2}, {0, 3}, {2, 3}, {0, 2}, {1, 3}}, {0, 1, 2, 3} },
            { 12, {{1, 2}, {2, 8}, {6, 11}, {1, 11}, {3, 7}, {2, 10}, {1, 4}, {4, 7}, {1, 7}, {0, 2}, {4, 8}, {3, 6}, {5, 9}, {1, 9}, {3, 11}}, {0, 2, 1, 5, 3, 4, 6, 4, 4, 3, 2, 7} },
            { 2, {{0, 1}}, {0, 1} },
            { 15, {{9, 10}, {1, 12}, {2, 4}, {1, 5}, {1, 11}, {0, 3}, {2, 3}, {8, 13}, {4, 5}, {1, 7}, {9, 14}, {1, 6}, {2, 5}, {7, 14}}, {0, 5, 2, 1, 3, 4, 6, 6, 0, 8, 9, 6, 6, 1, 7} },
            { 18, {{3, 4}, {3, 7}, {8, 12}, {0, 8}, {11, 17}, {6, 11}, {12, 15}, {3, 12}, {5, 9}, {14, 15}, {9, 10}, {9, 16}, {8, 14}, {0, 1}, {1, 2}, {11, 16}, {2, 16}, {6, 13}, {3, 11}, {3, 14}, {9, 15}, {0, 6}, {2, 6}, {1, 10}}, {0, 1, 2, 5, 6, 11, 3, 6, 7, 10, 11, 4, 6, 4, 8, 9, 11, 5} },
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
            
            vector<int> result = sol.getDepths(tc.n, tc.edges);
            
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
