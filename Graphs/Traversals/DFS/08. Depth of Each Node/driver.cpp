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
            { 17, {{1, 11}, {5, 7}, {8, 9}, {1, 13}, {3, 12}, {4, 11}, {3, 15}}, {0, 0, 0, 0, 2, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0} },
            { 7, {{2, 4}, {1, 2}, {5, 6}, {0, 5}}, {0, 0, 1, 0, 2, 1, 2} },
            { 12, {{2, 4}, {2, 7}, {2, 10}, {1, 8}, {5, 7}, {4, 5}, {5, 10}, {5, 6}, {1, 6}}, {0, 0, 4, 0, 3, 2, 1, 5, 1, 0, 5, 0} },
            { 19, {{10, 15}, {4, 16}, {3, 11}, {1, 11}, {12, 16}, {4, 14}, {2, 15}, {13, 15}, {16, 17}, {7, 14}}, {0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 1, 2, 2, 1, 1, 1, 2, 0} },
            { 7, {{1, 2}, {3, 4}, {4, 6}, {0, 3}, {1, 4}, {4, 5}, {0, 5}, {2, 5}}, {0, 3, 4, 1, 2, 5, 3} },
            { 20, {{1, 2}, {5, 17}, {2, 5}, {12, 15}, {11, 14}}, {0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 3, 0, 0} },
            { 11, {{0, 4}, {4, 9}, {0, 2}, {3, 6}, {0, 5}, {1, 10}, {5, 9}, {1, 6}, {2, 8}}, {0, 0, 1, 2, 1, 3, 1, 0, 2, 2, 1} },
            { 9, {{0, 7}, {3, 8}, {1, 3}, {7, 8}}, {0, 4, 0, 3, 0, 0, 0, 1, 2} },
            { 15, {{0, 4}, {9, 12}, {1, 14}, {1, 13}, {7, 11}}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1} },
            { 2, {}, {0, 0} },
            { 14, {{9, 11}, {0, 9}, {1, 4}, {3, 9}, {0, 5}, {1, 6}, {0, 11}}, {0, 0, 0, 2, 1, 1, 1, 0, 0, 1, 0, 2, 0, 0} },
            { 13, {{4, 10}, {0, 4}, {1, 11}, {7, 10}, {6, 8}, {4, 12}, {0, 2}, {1, 10}, {1, 6}, {0, 8}, {3, 5}}, {0, 3, 1, 0, 1, 1, 4, 3, 5, 0, 2, 4, 2} },
            { 19, {{13, 14}, {0, 4}, {13, 17}, {3, 18}, {5, 14}, {14, 15}, {0, 12}, {6, 7}, {3, 5}, {8, 9}, {0, 2}, {0, 18}, {9, 11}, {9, 17}, {15, 18}, {1, 9}, {3, 12}}, {0, 8, 1, 2, 1, 3, 0, 1, 8, 7, 0, 8, 1, 5, 4, 5, 0, 6, 6} },
            { 10, {}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} },
            { 2, {}, {0, 0} }
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
