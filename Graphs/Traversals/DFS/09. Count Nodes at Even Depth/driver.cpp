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
            { 13, {{4, 10}, {0, 10}, {6, 11}}, 11 },
            { 7, {{2, 4}, {0, 4}, {1, 5}, {0, 2}}, 5 },
            { 7, {{1, 2}, {0, 4}, {4, 6}, {2, 3}, {0, 2}, {0, 5}, {1, 6}}, 4 },
            { 20, {{3, 4}, {4, 9}, {12, 13}, {5, 7}, {4, 15}, {3, 19}, {9, 14}, {0, 5}, {1, 9}, {7, 19}, {5, 6}, {12, 15}, {1, 5}, {2, 13}, {7, 9}, {15, 16}, {7, 18}, {4, 10}, {4, 19}, {17, 19}, {0, 15}, {11, 18}, {1, 19}}, 11 },
            { 15, {{9, 10}, {0, 7}, {2, 14}, {6, 11}, {5, 14}, {5, 8}, {1, 5}, {4, 6}, {0, 9}, {7, 13}, {2, 3}, {4, 8}, {8, 12}, {3, 12}, {11, 14}, {1, 9}}, 8 },
            { 14, {{0, 1}, {1, 12}, {2, 7}, {3, 7}, {0, 9}, {4, 12}, {10, 13}, {5, 13}, {7, 9}, {12, 13}, {2, 9}, {3, 6}, {7, 11}, {1, 3}, {4, 7}}, 7 },
            { 2, {}, 2 },
            { 7, {{4, 6}, {3, 4}}, 6 },
            { 10, {{1, 2}, {4, 9}, {6, 7}, {3, 9}, {0, 5}}, 6 },
            { 4, {}, 4 },
            { 13, {{9, 10}, {0, 7}, {2, 7}, {2, 10}, {1, 8}, {0, 9}, {4, 7}, {2, 9}, {11, 12}, {5, 6}, {4, 8}, {0, 5}, {0, 8}, {1, 3}, {2, 11}, {3, 11}}, 7 },
            { 18, {{0, 9}, {13, 16}, {0, 12}, {4, 8}, {3, 15}, {3, 5}}, 12 },
            { 17, {{1, 12}, {5, 11}, {9, 13}, {3, 4}, {4, 9}, {6, 14}, {0, 9}, {13, 16}, {2, 13}, {11, 12}, {6, 7}, {4, 15}, {1, 7}, {3, 9}, {5, 10}, {15, 16}, {3, 12}, {3, 5}}, 9 },
            { 7, {{1, 2}, {0, 6}, {5, 6}, {0, 5}, {1, 3}}, 4 },
            { 11, {{0, 1}, {0, 7}, {2, 4}, {1, 2}, {2, 7}, {1, 5}, {3, 7}, {0, 6}, {1, 10}, {4, 8}, {5, 9}, {7, 8}}, 6 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countEvenDepthNodes(tc.n, tc.edges);
            
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
