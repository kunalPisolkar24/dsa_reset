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
            { 7, {{1, 2}, {1, 4}, {2, 3}, {0, 2}, {2, 6}, {5, 6}, {3, 5}}, 3 },
            { 5, {{0, 1}, {2, 4}, {1, 2}, {0, 4}, {0, 2}}, 3 },
            { 3, {{0, 1}, {0, 2}}, 2 },
            { 3, {{0, 1}, {1, 2}}, 1 },
            { 19, {{4, 9}, {12, 16}, {4, 6}, {4, 12}, {9, 14}, {8, 18}, {1, 6}, {2, 5}, {3, 6}, {5, 12}, {10, 11}, {0, 10}, {2, 10}, {2, 16}, {2, 13}, {7, 15}, {12, 14}, {3, 11}, {12, 17}, {4, 16}, {3, 8}, {5, 8}, {3, 17}, {0, 3}, {11, 15}, {2, 15}}, 8 },
            { 8, {{0, 7}, {1, 2}, {0, 4}, {3, 4}, {1, 5}, {1, 4}, {1, 7}, {2, 6}, {3, 5}}, 2 },
            { 2, {{0, 1}}, 1 },
            { 8, {{0, 7}, {3, 7}, {5, 7}, {2, 3}, {4, 5}, {1, 7}, {1, 6}, {2, 5}, {1, 3}, {4, 7}}, 4 },
            { 19, {{5, 13}, {8, 9}, {8, 12}, {8, 18}, {1, 6}, {9, 11}, {1, 3}, {10, 18}, {10, 15}, {1, 12}, {1, 18}, {2, 14}, {7, 10}, {4, 11}, {4, 17}, {8, 14}, {10, 14}, {1, 8}, {7, 9}, {15, 16}, {6, 10}, {3, 11}, {3, 8}, {5, 14}, {0, 6}, {9, 18}, {1, 10}, {2, 15}}, 7 },
            { 20, {{4, 12}, {8, 9}, {5, 19}, {10, 18}, {2, 14}, {13, 14}, {6, 11}, {6, 14}, {12, 15}, {14, 18}, {9, 16}, {9, 19}, {0, 16}, {10, 17}, {15, 19}, {3, 17}, {9, 18}, {2, 12}, {1, 19}, {7, 8}}, 6 },
            { 4, {{0, 1}, {1, 2}, {0, 3}, {2, 3}, {0, 2}, {1, 3}}, 3 },
            { 16, {{6, 12}, {4, 9}, {3, 13}, {1, 3}, {0, 11}, {8, 11}, {10, 14}, {1, 14}, {7, 9}, {6, 13}, {12, 14}, {3, 5}, {4, 10}, {3, 14}, {0, 9}, {0, 6}, {2, 9}, {1, 7}, {11, 15}, {2, 12}, {2, 15}}, 7 },
            { 8, {{0, 1}, {2, 4}, {1, 2}, {3, 4}, {1, 5}, {2, 3}, {2, 6}, {3, 6}, {1, 6}, {3, 5}}, 3 },
            { 20, {{6, 15}, {3, 4}, {4, 15}, {17, 18}, {9, 17}, {2, 11}, {2, 8}, {15, 17}, {4, 5}, {12, 18}, {0, 7}, {9, 19}, {11, 16}, {2, 7}, {13, 16}, {1, 17}, {14, 17}, {10, 16}, {13, 15}}, 6 },
            { 4, {{2, 3}, {0, 2}, {1, 2}, {1, 3}}, 2 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.maxBFSWidth(tc.n, tc.edges);
            
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
