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
            { 5, {{2, 3}, {1, 3}, {1, 4}}, 3 },
            { 24, {{4, 21}, {0, 2}, {3, 13}, {14, 22}, {8, 12}, {3, 22}, {9, 20}, {15, 23}, {12, 21}, {5, 9}, {12, 18}, {14, 21}, {5, 12}, {4, 20}, {17, 23}, {2, 16}, {1, 17}, {7, 15}, {18, 21}, {3, 14}, {3, 17}, {0, 6}, {11, 15}, {2, 6}, {10, 19}, {1, 16}, {10, 22}, {16, 17}}, 23 },
            { 3, {{0, 2}}, 1 },
            { 25, {{3, 7}, {9, 11}, {10, 18}, {2, 14}, {3, 6}, {21, 24}, {3, 12}, {3, 15}, {5, 21}, {0, 10}, {9, 22}, {1, 17}, {15, 16}, {15, 19}, {4, 7}, {7, 24}, {5, 23}, {1, 13}, {9, 24}, {15, 18}, {7, 8}}, 21 },
            { 17, {{0, 7}, {4, 16}, {9, 13}, {0, 10}, {1, 15}, {10, 14}, {4, 9}, {11, 13}, {4, 6}, {8, 16}, {5, 7}, {14, 15}, {4, 5}, {6, 16}, {4, 14}, {1, 6}, {10, 12}, {2, 11}}, 15 },
            { 9, {{2, 3}, {1, 7}, {4, 7}}, 3 },
            { 4, {{0, 2}}, 1 },
            { 10, {{1, 3}, {2, 4}, {1, 8}, {1, 4}, {4, 5}, {3, 9}, {6, 9}, {7, 8}, {2, 8}}, 8 },
            { 19, {{2, 9}}, 1 },
            { 13, {{5, 8}, {1, 11}, {7, 10}, {4, 6}, {1, 4}, {2, 6}, {6, 10}, {7, 8}, {1, 10}, {3, 12}, {1, 9}, {8, 11}}, 10 },
            { 19, {{6, 18}, {14, 16}, {10, 12}, {2, 8}, {2, 14}, {0, 17}, {3, 9}, {12, 18}, {14, 15}, {9, 10}, {13, 16}, {6, 7}, {15, 16}, {6, 10}, {4, 7}, {4, 16}, {9, 12}, {1, 4}, {2, 3}, {2, 9}, {10, 16}, {8, 13}, {2, 12}, {1, 16}, {16, 17}}, 16 },
            { 7, {}, 0 },
            { 19, {{11, 16}, {0, 2}, {11, 15}, {5, 9}, {2, 8}}, 5 },
            { 9, {{0, 1}, {1, 2}, {5, 7}, {5, 6}, {0, 5}, {3, 6}}, 6 },
            { 6, {}, 0 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countTreeEdges(tc.n, tc.edges);
            
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
