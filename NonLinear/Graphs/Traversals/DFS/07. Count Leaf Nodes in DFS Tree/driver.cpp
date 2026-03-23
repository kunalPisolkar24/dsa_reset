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
            { 7, {{2, 4}, {1, 4}, {0, 5}, {3, 6}, {2, 5}, {3, 5}}, 2 },
            { 6, {{0, 1}, {2, 4}, {0, 4}, {1, 5}, {1, 4}, {2, 3}, {4, 5}, {2, 5}}, 2 },
            { 5, {{1, 2}, {0, 4}, {3, 4}, {1, 4}, {0, 2}, {1, 3}}, 1 },
            { 5, {{0, 1}, {2, 4}, {3, 4}, {1, 4}}, 2 },
            { 11, {{2, 4}, {1, 2}, {3, 7}, {2, 10}, {0, 3}, {3, 10}, {0, 6}, {7, 9}, {1, 7}, {8, 9}, {0, 2}, {6, 10}, {1, 10}, {0, 5}, {5, 9}, {3, 5}}, 3 },
            { 7, {{0, 1}, {1, 2}, {0, 4}, {3, 4}, {0, 3}, {1, 4}, {0, 2}, {5, 6}, {0, 5}, {3, 6}}, 2 },
            { 12, {{0, 1}, {9, 10}, {2, 7}, {6, 11}, {1, 11}, {6, 8}, {1, 8}, {0, 9}, {5, 10}, {4, 8}, {5, 9}, {1, 3}}, 4 },
            { 11, {{2, 10}, {0, 3}, {4, 6}, {7, 9}, {6, 7}, {2, 6}, {2, 5}, {1, 3}, {1, 9}, {2, 8}}, 4 },
            { 6, {{2, 4}, {1, 2}, {3, 4}, {0, 2}, {2, 5}}, 3 },
            { 11, {{9, 10}, {0, 7}, {3, 8}, {3, 4}, {1, 5}, {7, 10}, {4, 6}, {1, 4}, {5, 7}, {2, 9}, {4, 5}, {3, 9}, {5, 6}, {1, 6}, {6, 9}}, 4 },
            { 5, {{2, 4}, {1, 2}, {1, 4}, {2, 3}, {0, 2}, {1, 3}}, 2 },
            { 12, {{10, 11}, {0, 4}, {3, 4}, {6, 11}, {3, 7}, {6, 8}, {1, 4}, {7, 9}, {0, 2}, {4, 5}, {2, 8}}, 4 },
            { 16, {{6, 12}, {3, 4}, {4, 15}, {5, 10}, {9, 14}, {9, 11}, {0, 14}, {10, 12}, {10, 15}, {6, 8}, {4, 11}, {1, 8}, {7, 9}, {7, 12}, {5, 11}, {10, 13}, {1, 4}, {2, 9}, {7, 8}}, 5 },
            { 14, {{9, 10}, {1, 3}, {4, 13}, {1, 5}, {5, 8}, {7, 10}, {1, 13}, {5, 6}, {0, 5}, {8, 12}, {9, 11}, {6, 9}, {2, 11}}, 5 },
            { 13, {{0, 8}, {1, 9}, {0, 11}, {4, 5}, {4, 8}, {5, 12}, {8, 11}, {2, 4}, {1, 2}, {1, 5}, {7, 9}, {6, 7}, {3, 5}, {3, 11}, {4, 10}, {9, 12}, {1, 4}, {1, 10}, {7, 8}}, 4 }
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
