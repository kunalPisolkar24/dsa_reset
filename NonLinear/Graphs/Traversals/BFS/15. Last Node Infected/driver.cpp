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
            { 6, {{2, 4}, {1, 5}, {2, 3}, {0, 2}, {0, 5}, {3, 5}}, {1}, 4 },
            { 6, {{0, 1}, {1, 2}, {3, 4}, {1, 5}, {0, 3}, {1, 4}, {2, 3}, {0, 5}, {1, 3}}, {4, 5}, 2 },
            { 20, {{12, 16}, {4, 6}, {3, 16}, {4, 18}, {0, 5}, {9, 14}, {1, 6}, {7, 16}, {7, 19}, {4, 14}, {4, 11}, {8, 11}, {0, 1}, {0, 7}, {9, 19}, {0, 16}, {1, 11}, {0, 13}, {4, 16}, {5, 8}, {17, 19}, {2, 12}, {1, 16}, {2, 15}}, {7, 15, 5}, 6 },
            { 9, {{0, 1}, {0, 7}, {2, 7}, {3, 7}, {6, 8}, {4, 6}, {2, 3}, {1, 7}, {2, 6}, {4, 8}, {2, 5}}, {1}, 4 },
            { 4, {{2, 3}, {0, 3}, {1, 3}}, {1}, 0 },
            { 4, {{0, 1}, {2, 3}, {0, 3}, {1, 3}}, {2}, 0 },
            { 19, {{6, 15}, {3, 4}, {4, 6}, {4, 12}, {3, 10}, {14, 16}, {0, 5}, {0, 14}, {11, 17}, {6, 11}, {6, 8}, {4, 14}, {5, 9}, {0, 1}, {0, 4}, {0, 10}, {11, 16}, {14, 17}, {0, 9}, {5, 17}, {0, 6}, {1, 13}, {2, 6}, {1, 10}, {0, 18}, {6, 9}, {7, 14}}, {4, 6}, 13 },
            { 14, {{6, 12}, {0, 13}, {6, 8}, {2, 10}, {4, 12}, {3, 10}, {5, 7}, {12, 13}, {11, 12}, {1, 7}, {6, 13}, {3, 9}, {1, 10}, {9, 11}, {10, 12}}, {9}, 5 },
            { 11, {{5, 8}, {2, 9}, {4, 5}, {5, 10}, {1, 7}, {5, 6}, {5, 9}, {1, 9}, {3, 5}}, {4}, 7 },
            { 6, {{2, 4}, {1, 2}, {1, 5}, {2, 3}, {4, 5}, {0, 5}, {1, 3}, {3, 5}}, {0, 3}, 4 },
            { 9, {{0, 1}, {1, 2}, {2, 7}, {1, 5}, {0, 3}, {2, 3}, {4, 8}, {1, 6}, {2, 5}, {7, 8}}, {2, 7, 8}, 0 },
            { 11, {{9, 10}, {3, 4}, {2, 7}, {5, 8}, {3, 7}, {6, 8}, {0, 6}, {7, 9}, {6, 7}, {1, 7}, {0, 2}, {2, 6}, {5, 6}, {1, 10}, {3, 5}}, {0}, 4 },
            { 8, {{2, 4}, {3, 4}, {2, 7}, {3, 7}, {4, 6}, {2, 3}, {0, 2}, {2, 6}, {0, 5}, {1, 6}, {1, 3}}, {0}, 1 },
            { 8, {{0, 1}, {1, 2}, {4, 6}, {5, 7}, {1, 4}, {6, 7}, {0, 2}, {2, 6}, {3, 6}, {1, 6}, {1, 3}, {4, 7}}, {4, 3}, 0 },
            { 8, {{0, 4}, {3, 4}, {2, 7}, {2, 3}, {6, 7}, {0, 2}, {4, 5}, {2, 6}, {5, 6}, {1, 6}, {2, 5}}, {7, 1}, 4 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.lastNodeInfected(tc.n, tc.edges, tc.sources);
            
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
