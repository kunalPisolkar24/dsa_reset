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
    int u;
    int v;
    bool expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 16, {{5, 13}, {0, 12}, {4, 7}, {0, 2}, {11, 15}, {3, 6}, {2, 6}, {4, 14}, {7, 12}, {14, 15}, {3, 5}, {12, 14}}, 8, 5, false },
            { 10, {{0, 7}, {1, 4}}, 3, 7, false },
            { 14, {{3, 13}, {1, 10}}, 13, 7, false },
            { 12, {{4, 10}, {5, 11}, {0, 4}, {5, 8}, {0, 3}, {4, 6}, {5, 7}, {7, 9}, {2, 9}, {0, 5}, {9, 11}, {4, 11}, {1, 3}, {3, 5}}, 10, 10, true },
            { 14, {{9, 10}, {3, 8}, {0, 3}, {7, 9}, {5, 10}, {8, 9}, {1, 7}, {2, 6}, {1, 6}, {1, 3}}, 1, 12, false },
            { 13, {{5, 11}, {3, 4}, {7, 10}, {1, 8}, {2, 6}, {6, 10}, {5, 6}, {7, 11}, {3, 11}}, 12, 0, false },
            { 4, {{0, 2}}, 1, 1, true },
            { 16, {{0, 7}, {1, 12}, {6, 15}, {6, 9}, {5, 14}, {5, 8}, {0, 3}, {10, 13}, {7, 11}, {11, 12}, {0, 15}, {3, 9}, {4, 14}, {1, 6}, {0, 14}, {1, 3}, {5, 12}, {12, 14}}, 5, 0, true },
            { 17, {{4, 16}, {0, 4}, {4, 13}, {0, 10}, {11, 13}, {2, 16}, {13, 16}, {1, 8}, {5, 13}, {9, 14}, {1, 10}, {13, 15}, {6, 9}, {1, 9}, {12, 14}}, 4, 7, false },
            { 9, {{3, 4}, {6, 8}, {1, 8}, {5, 7}, {1, 7}, {5, 6}, {4, 8}}, 0, 7, false },
            { 16, {{11, 13}, {12, 13}, {3, 10}, {3, 13}, {7, 11}}, 8, 8, true },
            { 13, {{2, 4}, {10, 11}, {7, 10}, {8, 10}, {1, 4}, {0, 12}, {6, 7}, {1, 7}, {2, 6}, {1, 10}, {2, 11}, {5, 12}, {7, 8}, {2, 8}}, 7, 4, true },
            { 9, {{0, 1}, {5, 8}, {0, 3}, {1, 4}, {2, 5}}, 3, 6, false },
            { 18, {{5, 7}}, 1, 8, false },
            { 19, {{6, 12}, {7, 17}, {3, 4}, {3, 7}, {3, 16}, {5, 10}, {4, 18}, {9, 17}, {0, 14}, {10, 15}, {1, 18}, {13, 17}, {3, 6}, {14, 15}, {2, 4}, {10, 14}, {2, 10}, {1, 8}, {6, 10}, {1, 10}, {1, 16}, {7, 8}}, 1, 7, true }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            bool result = sol.hasPath(tc.n, tc.edges, tc.u, tc.v);
            
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
