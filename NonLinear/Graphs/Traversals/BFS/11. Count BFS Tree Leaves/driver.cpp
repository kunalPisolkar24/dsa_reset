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
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 6, {{0, 1}, {2, 4}, {0, 4}, {3, 4}, {2, 3}, {4, 5}, {0, 2}, {2, 5}, {3, 5}}, 4 },
            { 6, {{0, 1}, {0, 4}, {3, 4}, {1, 5}, {4, 5}, {2, 5}}, 2 },
            { 10, {{0, 7}, {2, 7}, {1, 5}, {3, 7}, {6, 8}, {4, 8}, {1, 6}, {1, 3}, {1, 9}, {7, 8}}, 5 },
            { 8, {{3, 4}, {2, 7}, {1, 5}, {0, 3}, {2, 3}, {2, 6}, {2, 5}, {1, 3}}, 4 },
            { 17, {{0, 1}, {8, 14}, {7, 10}, {6, 8}, {5, 13}, {0, 6}, {11, 12}, {15, 16}, {2, 6}, {7, 12}, {4, 8}, {12, 15}, {3, 12}, {9, 11}, {2, 5}}, 4 },
            { 8, {{0, 1}, {1, 5}, {4, 6}, {5, 7}, {3, 6}, {2, 5}, {4, 7}}, 2 },
            { 2, {{0, 1}}, 1 },
            { 14, {{1, 12}, {5, 11}, {4, 13}, {1, 5}, {0, 3}, {1, 8}, {0, 6}, {6, 7}, {6, 10}, {1, 6}, {2, 5}, {6, 9}, {4, 7}}, 8 },
            { 6, {{0, 1}, {2, 4}, {1, 2}, {1, 5}, {0, 3}, {1, 4}, {4, 5}, {1, 3}}, 4 },
            { 6, {{0, 1}, {2, 4}, {1, 2}, {3, 4}, {2, 3}, {4, 5}, {0, 5}, {2, 5}, {1, 3}}, 3 },
            { 8, {{2, 7}, {3, 7}, {4, 6}, {5, 7}, {0, 2}, {1, 7}, {3, 6}}, 3 },
            { 17, {{6, 15}, {4, 9}, {3, 7}, {3, 10}, {5, 7}, {5, 13}, {5, 16}, {9, 14}, {4, 8}, {4, 11}, {1, 2}, {2, 7}, {0, 16}, {6, 7}, {7, 12}, {4, 16}, {5, 11}, {8, 13}, {0, 15}, {11, 15}}, 7 },
            { 18, {{1, 2}, {0, 10}, {3, 4}, {10, 14}, {11, 16}, {13, 17}, {2, 10}, {0, 3}, {3, 16}, {0, 6}, {1, 17}, {11, 12}, {7, 9}, {0, 15}, {4, 8}, {2, 5}, {6, 9}}, 7 },
            { 12, {{5, 11}, {2, 7}, {1, 11}, {0, 3}, {0, 9}, {0, 6}, {6, 7}, {5, 10}, {4, 8}, {0, 8}, {3, 5}}, 5 },
            { 9, {{3, 7}, {6, 8}, {4, 6}, {1, 8}, {0, 8}, {3, 5}}, 2 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countBFSTreeLeaves(tc.n, tc.edges);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << tc.expected << Color::RESET << "\n"; cout << "     " << Color::RED << "Got:      " << result << Color::RESET << "\n";
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
