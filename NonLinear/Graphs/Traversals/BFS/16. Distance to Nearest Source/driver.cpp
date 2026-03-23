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
    vector<int> expected;
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { 4, {{0, 1}, {0, 2}, {1, 2}, {2, 3}}, {0}, {0, 1, 1, 2} },
            { 5, {{0, 4}, {3, 4}, {0, 3}, {1, 4}, {2, 3}}, {0}, {0, 2, 2, 1, 1} },
            { 12, {{0, 7}, {2, 7}, {1, 8}, {7, 9}, {6, 10}, {1, 10}, {8, 11}, {9, 11}, {2, 5}, {1, 3}, {1, 9}, {3, 5}}, {3, 0, 6, 9}, {0, 1, 2, 0, -1, 1, 0, 1, 2, 0, 1, 1} },
            { 12, {{4, 10}, {1, 2}, {0, 10}, {6, 11}, {7, 10}, {3, 10}, {5, 7}, {3, 9}, {0, 8}, {2, 11}}, {0, 10}, {0, -1, -1, 1, 1, 2, -1, 1, 1, 2, 0, -1} },
            { 6, {{0, 1}, {2, 4}, {1, 2}, {3, 4}, {0, 5}, {1, 3}, {3, 5}}, {1, 2}, {1, 0, 0, 1, 1, 2} },
            { 17, {{5, 15}, {1, 2}, {6, 11}, {4, 9}, {1, 11}, {2, 10}, {9, 12}, {11, 13}, {12, 16}, {2, 3}, {5, 10}, {0, 2}, {7, 12}, {9, 14}, {0, 8}, {10, 12}}, {0, 12, 2, 14, 3}, {0, 1, 0, 0, 2, 2, 3, 1, 1, 1, 1, 2, 0, 3, 0, 3, 1} },
            { 16, {{5, 10}, {1, 3}, {0, 11}, {2, 14}, {1, 15}, {6, 11}, {6, 8}, {5, 15}, {2, 13}, {6, 13}, {3, 8}, {5, 8}, {9, 12}, {1, 4}, {11, 12}, {2, 9}, {1, 7}, {0, 15}, {1, 10}, {6, 9}, {7, 8}}, {13, 12, 1, 2, 0}, {0, 0, 0, 1, 1, 2, 1, 1, 2, 1, 1, 1, 0, 0, 1, 1} },
            { 7, {{1, 2}, {0, 4}, {3, 4}, {1, 5}, {4, 6}, {2, 3}, {5, 6}, {0, 5}, {1, 3}, {3, 5}}, {6}, {2, 2, 3, 2, 1, 1, 0} },
            { 16, {{2, 14}, {13, 14}, {0, 10}, {11, 13}, {6, 8}, {6, 14}, {3, 7}, {7, 13}, {5, 7}, {4, 15}, {8, 9}, {1, 6}, {0, 14}, {14, 15}, {5, 12}}, {11, 12, 14, 13}, {1, 2, 1, 2, 2, 1, 1, 1, 2, 3, 2, 0, 0, 0, 0, 1} },
            { 15, {{2, 14}, {4, 10}, {9, 13}, {5, 11}, {2, 7}, {0, 9}, {2, 9}, {0, 2}, {1, 13}, {3, 13}, {6, 10}, {0, 5}, {7, 8}, {3, 12}, {7, 12}, {6, 9}, {0, 11}}, {3, 13, 10}, {2, 1, 2, 0, 1, 3, 1, 2, 3, 1, 0, 3, 1, 0, 3} },
            { 12, {{10, 11}, {5, 11}, {7, 10}, {6, 8}, {1, 8}, {8, 10}, {4, 6}, {0, 9}, {2, 3}, {5, 10}, {3, 9}, {6, 9}, {3, 11}}, {0, 4}, {0, 3, 3, 2, 0, 4, 1, 4, 2, 1, 3, 3} },
            { 9, {{3, 7}, {0, 2}, {1, 7}, {0, 5}, {3, 6}, {1, 3}, {7, 8}}, {7, 0}, {0, 1, 1, 1, -1, 1, 2, 0, 1} },
            { 17, {{6, 15}, {4, 6}, {5, 13}, {3, 13}, {2, 5}, {12, 15}, {14, 15}, {0, 1}, {10, 11}, {9, 13}, {0, 10}, {0, 13}, {2, 16}, {6, 10}, {7, 15}, {4, 10}, {4, 16}, {0, 9}, {8, 13}, {1, 16}, {13, 15}}, {5, 9, 2, 7, 15}, {1, 2, 0, 2, 2, 0, 1, 0, 2, 0, 2, 3, 1, 1, 1, 0, 1} },
            { 7, {{2, 4}, {1, 5}, {4, 5}, {5, 6}, {0, 5}, {3, 6}, {1, 6}, {2, 5}, {1, 3}}, {1}, {2, 0, 2, 1, 2, 1, 1} },
            { 8, {{0, 7}, {0, 4}, {3, 7}, {2, 3}, {1, 7}, {3, 6}, {2, 5}}, {7, 2}, {1, 1, 0, 1, 2, 1, 2, 0} }
        };

        
        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();
        
        cout << Color::BOLD << "Running " << totalCount << " Tests..." << Color::RESET << "\n\n";
        
        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            vector<int> result = sol.distanceToNearestSource(tc.n, tc.edges, tc.sources);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: ["; for(auto x:tc.expected) cout<<x<<","; cout<<"]" << Color::RESET << "\n"; cout << "     " << Color::RED << "Got:      ["; for(auto x:result) cout<<x<<","; cout<<"]" << Color::RESET << "\n";
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
