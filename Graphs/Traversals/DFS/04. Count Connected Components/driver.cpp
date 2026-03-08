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
            { 2, {}, 2 },
            { 5, {}, 5 },
            { 16, {{1, 12}, {4, 13}, {4, 9}, {4, 15}, {6, 13}, {10, 12}, {3, 11}}, 9 },
            { 5, {{1, 2}}, 4 },
            { 25, {{8, 20}, {14, 19}, {0, 8}, {3, 17}}, 21 },
            { 3, {{0, 2}}, 2 },
            { 14, {{0, 8}, {10, 11}, {3, 11}}, 11 },
            { 16, {{5, 15}, {8, 14}, {1, 3}, {5, 8}, {1, 11}, {7, 13}, {5, 13}, {9, 15}, {6, 13}, {10, 12}, {9, 14}, {5, 6}, {6, 9}, {2, 11}, {7, 8}}, 5 },
            { 23, {{13, 14}, {10, 21}, {8, 14}, {2, 17}, {12, 13}, {5, 18}, {1, 17}, {8, 9}, {11, 18}, {9, 20}, {4, 20}}, 12 },
            { 4, {{2, 3}, {0, 3}, {1, 3}, {0, 1}}, 1 },
            { 8, {{4, 5}, {0, 5}}, 6 },
            { 20, {{3, 4}, {12, 13}, {4, 12}, {5, 10}, {5, 19}, {1, 6}, {1, 3}, {0, 11}, {2, 8}, {1, 12}, {7, 13}, {12, 15}, {4, 14}, {5, 12}, {5, 18}, {2, 4}, {0, 4}, {0, 16}, {2, 13}, {4, 16}, {1, 13}, {11, 15}, {15, 18}}, 3 },
            { 13, {{9, 10}, {0, 7}, {3, 8}, {1, 2}, {0, 10}, {2, 10}, {1, 8}, {3, 10}, {7, 12}, {2, 5}, {2, 11}}, 3 },
            { 9, {{0, 7}, {3, 8}, {0, 4}, {5, 8}, {3, 7}, {4, 5}, {1, 7}, {5, 6}, {0, 5}, {1, 6}}, 2 },
            { 22, {{5, 11}, {1, 15}, {1, 11}, {6, 17}, {15, 18}, {5, 20}, {1, 10}, {2, 21}, {1, 3}}, 13 }
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
