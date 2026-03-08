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
            { 13, {{5, 10}, {3, 9}, {5, 6}, {0, 11}}, 1 },
            { 17, {{4, 9}, {3, 7}, {14, 16}, {0, 2}, {11, 14}, {2, 8}, {2, 14}, {13, 14}, {1, 15}, {6, 11}, {8, 11}, {9, 16}, {0, 4}, {1, 5}, {15, 16}, {10, 13}, {1, 4}, {11, 12}, {0, 6}, {13, 15}}, 10 },
            { 20, {{7, 17}, {11, 14}, {0, 11}, {7, 10}, {3, 6}, {14, 18}, {4, 11}, {8, 11}, {9, 16}, {13, 16}, {7, 9}, {12, 14}, {3, 11}, {0, 9}, {10, 13}, {11, 12}, {10, 16}, {10, 19}, {1, 10}}, 5 },
            { 15, {{1, 12}, {1, 2}, {10, 11}, {6, 13}, {5, 10}, {6, 10}, {2, 12}, {4, 14}, {0, 8}, {11, 14}, {1, 9}}, 1 },
            { 11, {{0, 2}}, 1 },
            { 4, {{0, 2}, {1, 2}}, 2 },
            { 3, {}, 0 },
            { 5, {{2, 4}, {1, 3}, {0, 2}}, 2 },
            { 23, {{2, 14}, {10, 21}, {13, 17}, {4, 9}, {10, 17}, {3, 20}, {18, 19}, {7, 9}, {1, 13}, {9, 14}, {12, 21}, {6, 19}, {3, 15}, {4, 20}}, 0 },
            { 16, {{5, 15}, {5, 11}, {4, 9}, {3, 7}, {0, 3}, {1, 14}, {14, 15}, {1, 4}, {7, 9}, {6, 10}, {1, 10}, {4, 11}, {1, 3}, {3, 5}}, 7 },
            { 12, {{1, 5}, {2, 10}, {7, 9}, {0, 5}, {1, 10}, {5, 9}, {2, 8}}, 5 },
            { 5, {{0, 4}, {3, 4}}, 2 },
            { 23, {{0, 10}, {0, 16}, {1, 11}, {6, 8}, {19, 20}, {18, 19}, {9, 15}, {7, 22}, {8, 9}, {19, 22}, {9, 14}, {0, 5}, {4, 11}, {10, 18}, {16, 17}}, 5 },
            { 21, {{11, 20}, {1, 7}, {9, 18}}, 0 },
            { 14, {{4, 10}, {3, 8}, {5, 8}, {7, 10}, {0, 3}, {8, 10}, {4, 6}, {1, 4}, {7, 8}, {2, 11}, {5, 12}, {0, 11}}, 6 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.longestDFSChain(tc.n, tc.edges);
            
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
