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
            { 18, {{6, 12}, {12, 16}, {0, 2}, {0, 5}, {1, 9}, {6, 17}, {0, 10}, {2, 7}, {1, 5}, {0, 13}, {2, 16}, {15, 16}, {7, 15}, {9, 12}, {1, 4}, {9, 15}, {10, 13}, {0, 15}, {11, 15}, {7, 11}}, {1, 1, 1, 15} },
            { 12, {{2, 4}, {0, 4}, {2, 7}, {8, 10}, {5, 7}, {7, 9}, {6, 7}, {2, 9}, {2, 6}, {1, 10}, {3, 5}}, {1, 3, 8} },
            { 23, {{5, 15}}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2} },
            { 6, {{2, 3}, {0, 2}, {1, 2}, {3, 4}}, {1, 5} },
            { 7, {{0, 1}, {2, 4}, {1, 2}, {0, 4}, {2, 3}, {4, 5}}, {1, 6} },
            { 15, {{9, 10}, {10, 11}, {0, 3}, {8, 10}, {7, 9}, {3, 13}, {4, 5}, {8, 9}, {7, 12}, {3, 12}, {4, 11}, {2, 5}, {2, 11}}, {1, 1, 1, 12} },
            { 4, {{0, 3}, {1, 3}}, {1, 3} },
            { 9, {}, {1, 1, 1, 1, 1, 1, 1, 1, 1} },
            { 22, {{6, 12}, {6, 21}, {12, 16}, {4, 21}, {5, 19}, {1, 6}, {17, 18}, {10, 18}, {2, 14}, {1, 12}, {0, 20}, {1, 2}, {11, 13}, {8, 20}, {1, 14}, {16, 18}, {5, 14}, {0, 3}, {5, 20}, {2, 9}, {1, 13}, {6, 9}, {7, 14}}, {1, 21} },
            { 9, {{0, 1}, {4, 6}, {5, 7}, {0, 6}, {1, 6}}, {1, 1, 1, 2, 4} },
            { 12, {{0, 1}, {4, 9}, {7, 10}, {2, 5}, {1, 3}, {2, 8}}, {1, 1, 2, 2, 3, 3} },
            { 11, {{4, 8}, {1, 7}, {1, 10}, {0, 8}}, {1, 1, 1, 1, 1, 3, 3} },
            { 16, {{2, 14}, {13, 14}, {5, 15}, {4, 10}, {5, 8}, {1, 11}, {6, 11}, {2, 10}, {3, 7}, {8, 10}, {5, 7}, {4, 15}, {0, 2}, {1, 13}, {7, 15}, {0, 14}, {1, 9}, {3, 11}}, {1, 15} },
            { 15, {{2, 4}, {4, 9}, {0, 9}, {3, 10}, {10, 13}, {7, 9}, {4, 8}, {4, 7}, {3, 5}, {3, 11}}, {1, 1, 1, 1, 5, 6} },
            { 17, {{12, 16}, {4, 6}, {8, 9}, {9, 14}, {2, 14}, {10, 15}, {3, 9}, {4, 8}, {5, 12}, {0, 16}, {1, 11}, {6, 7}, {9, 12}, {8, 10}, {0, 9}, {1, 4}, {0, 12}, {8, 13}, {10, 16}}, {17} }
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
