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
            { 5, {{2, 4}, {1, 2}, {3, 4}, {0, 3}, {1, 4}, {2, 3}, {1, 3}}, 1 },
            { 4, {{0, 1}, {1, 2}, {1, 3}, {0, 3}}, 1 },
            { 3, {{0, 1}, {0, 2}, {1, 2}}, 1 },
            { 2, {{0, 1}}, 1 },
            { 16, {{0, 1}, {2, 14}, {2, 7}, {6, 9}, {6, 14}, {8, 10}, {7, 13}, {5, 6}, {10, 12}, {4, 11}, {2, 11}, {8, 11}, {3, 11}}, 3 },
            { 4, {{0, 1}, {1, 2}, {0, 3}, {2, 3}, {1, 3}}, 1 },
            { 11, {{0, 7}, {3, 8}, {2, 4}, {0, 4}, {0, 10}, {2, 7}, {3, 4}, {4, 9}, {1, 4}, {0, 6}, {7, 9}, {0, 2}, {3, 9}, {0, 5}}, 1 },
            { 5, {{0, 2}, {1, 3}, {3, 4}, {0, 4}}, 1 },
            { 5, {{0, 1}, {1, 2}, {1, 4}, {0, 2}, {1, 3}}, 1 },
            { 13, {{1, 2}, {0, 10}, {2, 10}, {9, 12}, {4, 6}, {3, 10}, {7, 9}, {3, 6}, {3, 12}, {5, 9}, {2, 11}, {2, 8}}, 1 },
            { 11, {{2, 4}, {1, 2}, {3, 4}, {1, 5}, {7, 10}, {2, 10}, {1, 7}, {5, 10}, {3, 9}, {0, 2}, {0, 5}, {1, 10}, {1, 6}, {1, 9}, {2, 8}}, 1 },
            { 20, {{3, 4}, {9, 14}, {5, 19}, {8, 12}, {1, 6}, {9, 17}, {17, 18}, {0, 5}, {11, 17}, {13, 14}, {1, 18}, {6, 11}, {4, 14}, {4, 11}, {14, 15}, {8, 11}, {0, 16}, {2, 13}, {2, 19}, {1, 17}, {15, 16}, {6, 16}, {3, 17}, {8, 10}, {7, 8}}, 1 },
            { 10, {{2, 4}, {5, 8}, {1, 5}, {0, 3}, {4, 6}, {1, 4}, {3, 9}, {4, 8}, {1, 6}, {1, 3}, {3, 5}}, 2 },
            { 20, {{5, 16}, {0, 5}, {8, 12}, {17, 18}, {2, 14}, {2, 17}, {15, 17}, {7, 16}, {6, 8}, {18, 19}, {6, 17}, {5, 6}, {3, 6}, {3, 12}, {8, 11}, {0, 1}, {5, 15}, {0, 4}, {1, 17}, {7, 15}, {4, 13}, {0, 9}, {8, 16}, {8, 13}, {2, 9}, {10, 16}, {1, 16}, {13, 15}}, 1 },
            { 24, {{18, 23}, {20, 23}, {3, 10}, {5, 19}, {0, 8}, {0, 11}, {0, 23}, {1, 18}, {6, 11}, {7, 16}, {12, 21}, {5, 9}, {4, 11}, {17, 23}, {0, 10}, {2, 16}, {13, 16}, {2, 19}, {2, 22}, {2, 12}, {13, 15}, {7, 14}}, 2 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countComponents(tc.n, tc.edges);
            
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
