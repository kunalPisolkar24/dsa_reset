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
    int start;
    int expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 6, {{0, 1}, {1, 2}, {1, 4}}, 5, 1 },
            { 7, {{1, 5}, {4, 6}, {0, 6}, {2, 3}, {5, 6}, {0, 5}}, 4, 5 },
            { 6, {{0, 1}, {2, 4}, {0, 4}, {3, 4}, {1, 4}, {2, 5}}, 0, 6 },
            { 19, {}, 6, 1 },
            { 14, {{1, 13}}, 10, 1 },
            { 12, {{4, 10}, {1, 2}, {5, 8}, {4, 9}, {7, 9}, {1, 10}}, 5, 2 },
            { 9, {{0, 1}, {2, 6}, {0, 6}}, 6, 4 },
            { 7, {{4, 6}, {2, 6}, {5, 6}, {1, 4}}, 3, 1 },
            { 18, {{9, 16}, {8, 14}, {0, 7}, {1, 15}, {3, 4}, {3, 17}, {8, 17}, {12, 16}, {6, 8}, {7, 9}, {4, 5}, {2, 6}, {7, 15}, {2, 15}, {0, 8}, {1, 3}}, 0, 15 },
            { 5, {{2, 4}, {3, 4}, {0, 2}}, 0, 4 },
            { 16, {{7, 15}}, 12, 1 },
            { 8, {}, 4, 1 },
            { 5, {}, 2, 1 },
            { 13, {{4, 12}, {3, 10}, {7, 12}, {3, 6}, {3, 5}}, 4, 3 },
            { 4, {{0, 2}}, 3, 1 }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            int result = sol.countReachable(tc.n, tc.edges, tc.start);
            
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
