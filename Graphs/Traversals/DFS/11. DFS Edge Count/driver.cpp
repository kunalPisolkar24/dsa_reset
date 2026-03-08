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
            { 5, {{0, 1}, {1, 2}, {0, 4}, {3, 4}, {0, 3}, {0, 2}, {1, 3}}, 4 },
            { 4, {{0, 1}, {1, 2}, {0, 3}, {2, 3}, {0, 2}, {1, 3}}, 3 },
            { 11, {{0, 1}, {3, 8}, {0, 4}, {4, 9}, {8, 10}, {0, 6}, {2, 3}, {5, 9}, {0, 8}, {7, 8}}, 10 },
            { 13, {{3, 8}, {5, 11}, {2, 7}, {4, 9}, {2, 10}, {1, 4}, {2, 9}, {0, 2}, {7, 12}, {9, 11}, {6, 9}, {8, 11}}, 12 },
            { 2, {}, 0 },
            { 2, {{0, 1}}, 1 },
            { 11, {{9, 10}, {0, 7}, {2, 7}, {4, 9}, {2, 3}, {1, 7}, {8, 9}, {2, 5}, {6, 9}}, 9 },
            { 3, {{0, 2}, {1, 2}}, 2 },
            { 19, {{6, 15}, {4, 6}, {17, 18}, {2, 5}, {10, 12}, {1, 9}, {0, 11}, {2, 14}, {1, 18}, {7, 10}, {6, 14}, {5, 9}, {4, 11}, {5, 12}, {8, 11}, {5, 18}, {9, 10}, {9, 13}, {2, 16}, {3, 5}, {3, 8}, {5, 14}, {0, 3}, {9, 12}, {1, 13}, {11, 15}, {7, 14}}, 18 },
            { 24, {{3, 4}, {3, 13}, {5, 16}, {8, 12}, {1, 6}, {13, 17}, {6, 11}, {7, 13}, {18, 19}, {14, 21}, {9, 16}, {2, 4}, {0, 4}, {10, 14}, {19, 20}, {1, 17}, {6, 16}, {4, 16}, {3, 14}, {12, 23}, {3, 20}, {17, 22}, {9, 18}, {11, 15}, {13, 18}}, 22 },
            { 24, {{7, 20}, {5, 7}, {6, 8}, {6, 14}, {15, 23}, {6, 17}, {12, 21}, {3, 21}, {5, 15}, {0, 10}, {2, 7}, {1, 11}, {11, 13}, {11, 19}, {10, 17}, {2, 10}, {6, 16}, {6, 22}, {4, 10}, {12, 23}, {5, 11}, {5, 8}, {11, 12}, {0, 12}, {2, 9}, {0, 18}}, 23 },
            { 23, {{16, 20}, {7, 17}, {6, 15}, {12, 22}, {3, 19}, {17, 18}, {8, 15}, {8, 21}, {19, 21}, {1, 9}, {2, 17}, {3, 9}, {4, 8}, {17, 20}, {10, 14}, {1, 17}, {3, 5}, {3, 11}, {3, 14}, {12, 20}, {3, 20}, {8, 10}, {17, 22}, {10, 16}, {0, 15}, {13, 21}}, 22 },
            { 6, {{0, 1}, {1, 2}, {3, 4}, {1, 4}, {2, 3}, {0, 2}, {1, 3}, {3, 5}}, 5 },
            { 20, {{14, 19}, {5, 16}, {5, 10}, {8, 9}, {8, 12}, {5, 19}, {1, 6}, {0, 8}, {11, 17}, {8, 11}, {1, 11}, {6, 7}, {6, 13}, {7, 12}, {3, 11}, {1, 4}, {2, 6}, {1, 10}, {11, 18}, {15, 18}, {7, 8}}, 19 },
            { 17, {{6, 15}, {3, 7}, {3, 16}, {5, 7}, {8, 15}, {1, 3}, {1, 9}, {10, 15}, {1, 15}, {7, 10}, {7, 16}, {8, 11}, {8, 14}, {9, 13}, {2, 7}, {11, 13}, {6, 13}, {7, 12}, {5, 11}, {5, 8}, {0, 9}, {1, 4}, {2, 6}}, 16 }
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
