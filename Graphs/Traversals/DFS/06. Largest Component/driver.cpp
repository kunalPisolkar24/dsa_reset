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
            { 25, {{5, 21}, {0, 20}, {1, 21}, {3, 17}, {6, 8}, {2, 19}, {4, 5}, {2, 22}, {3, 11}}, 4 },
            { 12, {{2, 4}, {5, 11}, {0, 4}, {0, 10}, {5, 8}, {7, 10}, {2, 10}, {1, 8}, {3, 7}, {1, 4}, {0, 6}, {5, 10}, {0, 2}, {4, 11}}, 11 },
            { 11, {{4, 10}, {2, 7}, {5, 8}, {7, 10}, {0, 3}, {3, 10}, {1, 4}, {7, 9}, {6, 7}, {1, 7}, {1, 10}}, 9 },
            { 2, {{0, 1}}, 2 },
            { 5, {{2, 3}, {1, 4}}, 2 },
            { 24, {{3, 17}, {12, 13}, {0, 12}, {8, 9}, {7, 12}, {3, 6}, {15, 22}, {10, 22}, {3, 15}, {2, 11}}, 6 },
            { 8, {{6, 7}, {4, 5}, {0, 3}}, 2 },
            { 3, {{0, 2}}, 2 },
            { 14, {{4, 10}, {1, 5}, {1, 11}, {11, 12}, {7, 12}, {2, 6}, {3, 6}, {1, 6}, {5, 12}}, 8 },
            { 24, {{16, 19}, {4, 22}, {15, 23}, {0, 9}, {15, 16}, {8, 11}}, 4 },
            { 11, {{1, 3}}, 2 },
            { 22, {{9, 16}, {5, 11}, {14, 17}, {2, 20}, {7, 10}, {0, 13}, {15, 20}, {10, 20}, {4, 15}, {13, 19}, {1, 17}, {14, 16}, {6, 13}, {15, 19}, {2, 21}, {1, 3}, {0, 17}}, 17 },
            { 8, {{0, 1}, {1, 2}, {0, 4}, {1, 5}, {1, 4}, {4, 5}, {0, 2}, {4, 7}}, 6 },
            { 15, {{0, 1}, {3, 14}, {10, 14}, {11, 13}, {8, 10}, {0, 9}, {2, 13}, {0, 2}, {4, 5}, {1, 7}, {5, 6}, {1, 10}, {1, 6}, {2, 5}, {7, 8}}, 14 },
            { 6, {}, 1 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.largestComponent(tc.n, tc.edges);
            
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
