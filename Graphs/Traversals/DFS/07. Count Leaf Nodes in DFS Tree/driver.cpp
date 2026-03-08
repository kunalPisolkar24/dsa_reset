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
            { 18, {{4, 9}, {9, 11}, {1, 9}, {2, 8}, {13, 14}, {7, 10}, {7, 13}, {3, 6}, {4, 17}, {8, 14}, {2, 4}, {0, 16}, {6, 7}, {12, 14}, {4, 16}, {3, 17}, {0, 3}, {5, 17}, {0, 12}, {10, 16}, {7, 14}}, 5 },
            { 13, {{4, 10}, {3, 8}, {0, 10}, {9, 12}, {4, 6}, {3, 10}, {0, 2}, {3, 9}, {3, 5}}, 5 },
            { 5, {{0, 2}}, 1 },
            { 10, {{0, 1}, {2, 4}, {1, 5}, {1, 8}, {2, 9}, {4, 5}, {5, 6}, {0, 5}, {3, 6}}, 3 },
            { 18, {{9, 17}, {0, 5}, {8, 17}, {3, 6}}, 1 },
            { 14, {{11, 13}, {1, 9}}, 1 },
            { 20, {{7, 17}, {6, 15}, {4, 12}, {14, 16}, {5, 13}, {14, 19}, {0, 2}, {9, 11}, {17, 18}, {11, 14}, {10, 18}, {7, 16}, {15, 17}, {6, 8}, {0, 18}, {3, 12}, {8, 11}, {8, 14}, {2, 19}, {16, 18}, {12, 17}, {0, 12}, {8, 19}, {0, 15}, {2, 18}, {11, 18}}, 5 },
            { 17, {{6, 12}, {3, 16}, {5, 16}, {0, 5}, {8, 12}, {1, 3}, {0, 11}, {7, 13}, {4, 14}, {5, 15}, {10, 11}, {1, 2}, {0, 13}, {1, 14}, {9, 12}, {0, 3}, {0, 15}, {1, 10}, {13, 15}}, 4 },
            { 6, {{4, 5}, {2, 4}}, 1 },
            { 12, {{0, 1}, {1, 2}, {3, 7}, {4, 6}, {1, 8}, {0, 6}, {2, 3}, {5, 6}, {4, 11}, {2, 11}, {4, 7}}, 3 },
            { 19, {{0, 1}, {2, 17}, {6, 8}, {5, 17}, {0, 6}, {0, 12}, {4, 11}, {2, 5}, {6, 9}, {7, 8}, {11, 17}}, 4 },
            { 3, {{0, 2}}, 1 },
            { 7, {{0, 4}, {1, 5}, {4, 6}, {0, 2}, {3, 6}, {3, 5}}, 2 },
            { 11, {{4, 10}, {2, 4}, {2, 7}, {7, 10}, {8, 10}, {5, 10}, {0, 5}, {1, 3}, {1, 9}}, 2 },
            { 17, {{3, 7}, {8, 9}, {11, 14}, {1, 3}, {1, 12}, {6, 11}, {12, 15}, {8, 11}, {9, 13}, {0, 4}, {10, 14}, {2, 10}, {5, 14}, {1, 4}, {0, 6}, {8, 13}, {1, 13}, {2, 12}, {2, 15}, {13, 15}}, 4 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countLeafNodes(tc.n, tc.edges);
            
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
