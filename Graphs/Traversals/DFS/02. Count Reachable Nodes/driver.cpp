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
    int start;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 5, {{0, 1}, {0, 2}, {0, 3}}, 0, 4 },
            { 7, {{2, 4}, {1, 2}, {0, 4}, {1, 5}, {1, 4}, {2, 3}, {5, 6}, {1, 3}}, 6, 7 },
            { 19, {{6, 18}, {4, 6}, {2, 11}, {1, 12}, {13, 17}, {4, 14}, {4, 17}, {9, 10}, {1, 2}, {2, 7}, {1, 5}, {2, 10}, {7, 15}, {7, 18}, {4, 7}, {3, 5}, {4, 16}, {0, 9}, {8, 10}, {10, 13}, {2, 3}}, 17, 19 },
            { 2, {{0, 1}}, 0, 2 },
            { 14, {{5, 12}, {4, 13}, {2, 11}, {3, 10}, {12, 13}, {0, 6}, {7, 9}, {0, 12}, {11, 12}, {8, 13}, {0, 8}, {1, 3}, {4, 7}}, 13, 11 },
            { 4, {{0, 1}, {1, 2}, {0, 3}, {0, 2}, {1, 3}}, 1, 4 },
            { 7, {{0, 1}, {0, 4}, {1, 5}, {4, 6}, {0, 3}, {4, 5}, {2, 6}, {0, 5}, {1, 6}, {1, 3}}, 2, 7 },
            { 11, {{9, 10}, {0, 7}, {2, 4}, {1, 2}, {2, 7}, {0, 3}, {0, 9}, {0, 6}, {5, 10}, {3, 9}, {0, 5}, {7, 8}}, 9, 11 },
            { 15, {{3, 7}, {3, 10}, {8, 12}, {2, 5}, {5, 6}, {3, 6}, {0, 1}, {2, 4}, {8, 14}, {0, 4}, {9, 13}, {0, 13}, {2, 10}, {2, 13}, {3, 11}, {5, 8}, {0, 9}, {0, 6}, {1, 13}, {7, 8}}, 11, 15 },
            { 11, {{0, 7}, {4, 9}, {7, 10}, {1, 8}, {6, 7}, {2, 9}, {4, 5}, {6, 10}, {3, 6}, {5, 9}, {0, 8}, {4, 7}, {2, 8}}, 2, 11 },
            { 19, {{3, 7}, {4, 12}, {4, 18}, {9, 11}, {9, 17}, {10, 18}, {7, 16}, {3, 6}, {9, 16}, {5, 15}, {1, 2}, {1, 14}, {7, 12}, {16, 18}, {4, 10}, {8, 10}, {0, 9}, {1, 7}, {1, 13}, {0, 15}, {1, 10}, {2, 15}}, 13, 19 },
            { 6, {{0, 1}, {0, 4}, {1, 5}, {1, 4}, {4, 5}, {0, 2}, {2, 5}, {3, 5}}, 5, 6 },
            { 11, {{0, 1}, {0, 4}, {3, 4}, {0, 9}, {3, 10}, {5, 7}, {0, 6}, {4, 8}, {3, 5}, {2, 8}}, 1, 11 },
            { 10, {{0, 7}, {6, 8}, {1, 8}, {2, 6}, {5, 6}, {4, 8}, {0, 5}, {3, 6}, {1, 9}}, 9, 10 },
            { 17, {{6, 15}, {0, 10}, {0, 16}, {1, 5}, {12, 16}, {9, 12}, {13, 16}, {6, 14}, {8, 13}, {2, 9}, {5, 9}, {4, 14}, {9, 11}, {6, 9}, {3, 11}}, 11, 16 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countReachable(tc.n, tc.edges, tc.start);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << tc.expected << Color::RESET << "\n";\
                cout << "     " << Color::RED << "Got:      " << result << Color::RESET << "\n";
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
