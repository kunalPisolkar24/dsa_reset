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
            { 5, {{0, 2}, {1, 3}, {2, 4}}, 2, 0, true },
            { 4, {{0, 1}, {2, 3}}, 0, 3, false },
            { 6, {{0, 1}, {1, 2}, {3, 4}, {4, 5}}, 0, 5, false },
            { 15, {{2, 14}, {3, 4}, {5, 8}, {1, 11}, {7, 10}, {10, 14}, {0, 3}, {4, 12}, {0, 9}, {5, 7}, {4, 7}, {2, 12}, {3, 6}, {0, 8}, {7, 11}, {1, 9}, {7, 14}}, 6, 2, true },
            { 4, {{0, 1}, {1, 2}, {1, 3}, {0, 3}}, 3, 1, true },
            { 18, {{2, 4}, {2, 17}, {3, 4}, {6, 11}, {7, 10}, {15, 17}, {6, 14}, {13, 16}, {1, 4}, {15, 16}, {0, 15}, {12, 15}, {9, 11}, {7, 11}, {14, 15}, {5, 12}, {2, 8}}, 1, 11, true },
            { 5, {{0, 1}, {1, 2}, {0, 2}}, 0, 4, false },
            { 8, {{0, 1}, {3, 7}, {2, 3}, {5, 6}, {1, 6}, {1, 3}, {4, 7}}, 0, 4, true },
            { 13, {{0, 7}, {4, 10}, {1, 4}, {6, 7}, {4, 5}, {8, 9}, {5, 6}, {9, 11}, {2, 5}, {6, 9}, {5, 12}, {3, 5}}, 5, 2, true },
            { 7, {{2, 4}, {0, 3}, {1, 4}, {0, 6}, {2, 6}, {3, 6}, {2, 5}}, 4, 6, true },
            { 3, {{0, 1}}, 1, 2, false },
            { 10, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {5, 6}, {6, 7}, {7, 8}, {8, 9}}, 0, 9, false },
            { 5, {}, 0, 4, false },
            { 11, {{0, 1}, {4, 10}, {0, 4}, {4, 9}, {0, 9}, {5, 7}, {0, 6}, {2, 3}, {2, 9}, {1, 7}, {4, 8}, {0, 8}}, 5, 10, true },
            { 6, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}}, 0, 3, true }
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
