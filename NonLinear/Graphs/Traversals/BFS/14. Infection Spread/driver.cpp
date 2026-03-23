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
    vector<int> sources;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 6, {{2, 4}, {1, 2}, {0, 4}, {1, 5}, {0, 3}, {0, 5}}, {5}, 2 },
            { 6, {{0, 1}, {1, 2}, {3, 4}, {1, 5}, {0, 3}, {0, 2}, {0, 5}}, {2, 3}, 2 },
            { 18, {{8, 14}, {4, 16}, {8, 17}, {11, 16}, {7, 10}, {6, 14}, {13, 16}, {5, 7}, {0, 2}, {8, 9}, {7, 12}, {1, 13}, {8, 12}, {0, 8}, {14, 15}, {3, 11}}, {10, 13, 9, 17, 0, 12}, 3 },
            { 5, {{0, 1}, {1, 2}, {0, 4}, {3, 4}, {0, 3}, {1, 4}}, {4}, 2 },
            { 12, {{0, 7}, {0, 4}, {0, 10}, {3, 4}, {1, 5}, {5, 8}, {7, 10}, {6, 8}, {0, 9}, {1, 4}, {1, 7}, {8, 9}, {3, 9}, {2, 6}, {4, 11}, {0, 8}, {7, 11}, {1, 3}}, {7, 0, 8}, 2 },
            { 17, {{2, 14}, {0, 7}, {9, 16}, {9, 10}, {8, 15}, {3, 4}, {2, 7}, {8, 14}, {2, 16}, {10, 13}, {0, 6}, {1, 7}, {6, 13}, {4, 5}, {2, 12}, {7, 11}, {3, 11}}, {6}, 6 },
            { 13, {{9, 10}, {4, 10}, {5, 11}, {3, 4}, {2, 7}, {9, 12}, {7, 9}, {5, 10}, {6, 10}, {1, 10}, {0, 8}, {2, 8}}, {0, 12, 10, 6}, 2 },
            { 17, {{0, 7}, {9, 16}, {4, 13}, {7, 14}, {7, 10}, {7, 13}, {3, 16}, {9, 15}, {8, 13}, {3, 13}, {1, 13}, {2, 6}, {3, 12}, {8, 11}, {2, 8}}, {8, 9}, 3 },
            { 9, {{2, 4}, {4, 6}, {0, 3}, {1, 4}, {0, 6}, {4, 5}, {3, 6}, {0, 8}, {7, 8}}, {4, 5}, 4 },
            { 13, {{4, 12}, {5, 7}, {0, 2}, {8, 9}, {0, 11}, {6, 11}, {7, 10}, {3, 9}, {5, 9}, {1, 11}, {1, 8}, {7, 9}, {6, 7}, {4, 7}, {9, 12}, {2, 3}, {0, 12}, {2, 9}, {7, 8}}, {11, 9, 8, 2}, 2 },
            { 17, {{13, 14}, {5, 14}, {4, 9}, {1, 14}, {7, 13}, {10, 13}, {2, 3}, {11, 12}, {2, 6}, {4, 8}, {1, 16}, {1, 6}, {4, 11}, {0, 14}, {2, 11}}, {7, 12, 5}, 3 },
            { 8, {{2, 4}, {1, 2}, {3, 7}, {0, 3}, {2, 3}, {6, 7}, {1, 6}}, {1, 5}, 3 },
            { 15, {{2, 4}, {7, 9}, {2, 9}, {0, 2}, {8, 13}, {3, 9}, {3, 12}, {0, 5}, {4, 14}, {8, 11}, {5, 10}, {1, 7}, {6, 9}, {7, 8}}, {13, 7}, 5 },
            { 10, {{3, 4}, {5, 8}, {2, 3}, {6, 7}, {4, 5}, {0, 5}, {1, 6}, {1, 3}, {1, 9}}, {9}, 5 },
            { 20, {{6, 18}, {12, 16}, {4, 18}, {10, 12}, {2, 14}, {1, 18}, {2, 17}, {7, 10}, {3, 9}, {3, 12}, {5, 12}, {9, 19}, {2, 7}, {0, 19}, {1, 8}, {2, 19}, {6, 13}, {3, 11}, {4, 10}, {4, 13}, {9, 15}, {2, 3}, {2, 12}, {2, 18}, {0, 18}}, {8}, 6 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.infectionSpread(tc.n, tc.edges, tc.sources);
            
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
