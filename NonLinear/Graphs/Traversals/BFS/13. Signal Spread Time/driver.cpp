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
            { 6, {{0, 1}, {2, 4}, {1, 2}, {0, 4}, {1, 5}, {1, 4}, {3, 5}}, 3 },
            { 4, {{0, 1}, {1, 2}, {0, 3}, {2, 3}, {1, 3}}, 2 },
            { 9, {{3, 4}, {0, 3}, {4, 5}, {1, 7}, {4, 8}, {1, 6}, {0, 8}}, 3 },
            { 3, {{0, 2}, {1, 2}}, 2 },
            { 15, {{9, 10}, {2, 4}, {5, 12}, {0, 4}, {1, 5}, {6, 9}, {0, 13}, {4, 12}, {7, 13}, {8, 13}, {1, 7}, {0, 2}, {2, 12}, {9, 14}, {11, 14}, {1, 3}, {1, 9}}, 6 },
            { 2, {{0, 1}}, 1 },
            { 9, {{2, 7}, {0, 3}, {4, 6}, {4, 5}, {2, 6}, {1, 6}, {0, 8}, {3, 5}, {2, 8}}, 4 },
            { 15, {{2, 14}, {0, 7}, {3, 4}, {0, 3}, {12, 13}, {8, 10}, {2, 13}, {5, 13}, {7, 9}, {2, 9}, {1, 13}, {7, 12}, {2, 12}, {1, 10}, {0, 8}, {1, 9}, {3, 11}}, 4 },
            { 17, {{6, 12}, {2, 14}, {4, 16}, {5, 8}, {3, 7}, {12, 16}, {1, 8}, {8, 10}, {1, 14}, {4, 12}, {0, 12}, {15, 16}, {3, 13}, {8, 9}, {2, 12}, {7, 11}, {8, 11}, {2, 8}}, 7 },
            { 5, {{0, 1}, {2, 4}, {1, 2}, {0, 3}, {1, 4}, {1, 3}}, 2 },
            { 12, {{9, 10}, {3, 8}, {1, 2}, {6, 9}, {3, 7}, {4, 6}, {5, 7}, {5, 10}, {0, 2}, {2, 6}, {5, 6}, {1, 7}, {5, 9}, {2, 11}, {3, 11}}, 4 },
            { 7, {{2, 4}, {0, 4}, {3, 4}, {1, 5}, {0, 6}, {4, 5}, {0, 2}, {2, 6}, {0, 5}, {3, 6}}, 2 },
            { 20, {{3, 10}, {3, 16}, {0, 5}, {9, 17}, {17, 18}, {4, 11}, {10, 11}, {8, 17}, {11, 13}, {2, 19}, {6, 13}, {7, 15}, {7, 18}, {3, 5}, {4, 13}, {0, 9}, {5, 17}, {7, 11}, {0, 12}, {8, 13}, {2, 3}, {0, 15}, {10, 19}, {0, 18}, {1, 19}, {7, 14}}, 5 },
            { 3, {{0, 1}, {0, 2}, {1, 2}}, 1 },
            { 20, {{12, 16}, {4, 12}, {12, 19}, {14, 16}, {17, 18}, {13, 14}, {6, 14}, {7, 13}, {7, 19}, {3, 9}, {14, 18}, {5, 12}, {1, 2}, {0, 10}, {2, 7}, {0, 19}, {10, 17}, {2, 13}, {6, 10}, {7, 18}, {12, 14}, {3, 8}, {5, 14}, {0, 9}, {8, 16}, {9, 15}, {1, 10}, {1, 16}, {11, 18}, {7, 11}}, 3 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.signalSpreadTime(tc.n, tc.edges);
            
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
