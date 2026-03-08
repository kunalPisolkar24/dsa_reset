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
            { 7, {}, {0, 1, 2, 3, 4, 5, 6} },
            { 3, {{0, 1}}, {0, 1, 2} },
            { 14, {{0, 10}, {1, 5}, {6, 11}, {0, 9}, {12, 13}, {2, 13}, {0, 12}, {8, 13}, {6, 13}, {3, 6}, {1, 9}}, {0, 9, 1, 5, 10, 12, 13, 2, 6, 3, 11, 8, 4, 7} },
            { 7, {{2, 4}, {1, 4}, {4, 5}, {2, 6}, {1, 3}}, {0, 1, 3, 4, 2, 6, 5} },
            { 18, {{16, 17}, {5, 13}}, {0, 1, 2, 3, 4, 5, 13, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17} },
            { 15, {{0, 1}}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14} },
            { 13, {{10, 11}}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12} },
            { 18, {{15, 16}, {4, 14}}, {0, 1, 2, 3, 4, 14, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17} },
            { 8, {{0, 7}}, {0, 7, 1, 2, 3, 4, 5, 6} },
            { 6, {{4, 5}}, {0, 1, 2, 3, 4, 5} },
            { 18, {{4, 12}, {3, 16}, {4, 15}, {0, 2}, {0, 8}, {10, 12}, {2, 11}, {10, 15}, {2, 17}, {7, 10}, {15, 17}, {4, 5}, {4, 11}, {10, 11}, {9, 13}, {10, 14}, {11, 13}, {2, 16}, {13, 16}, {6, 7}, {5, 11}, {9, 12}, {1, 7}}, {0, 2, 11, 4, 5, 12, 9, 13, 16, 3, 10, 7, 1, 6, 14, 15, 17, 8} },
            { 7, {{0, 4}, {3, 4}, {2, 3}, {0, 5}, {1, 3}, {3, 5}}, {0, 4, 3, 1, 2, 5, 6} },
            { 5, {{0, 4}, {3, 4}, {1, 4}}, {0, 4, 1, 3, 2} },
            { 14, {{9, 10}, {5, 11}, {2, 7}, {7, 10}, {9, 12}, {12, 13}, {2, 9}, {6, 13}, {5, 9}, {6, 10}, {0, 5}, {3, 6}, {1, 6}, {7, 11}, {10, 12}, {3, 5}}, {0, 5, 3, 6, 1, 10, 7, 2, 9, 12, 13, 11, 4, 8} },
            { 10, {{0, 7}, {2, 4}, {3, 4}, {3, 7}, {0, 3}, {2, 9}, {6, 7}, {3, 6}, {1, 3}}, {0, 3, 1, 4, 2, 9, 6, 7, 5, 8} }
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
