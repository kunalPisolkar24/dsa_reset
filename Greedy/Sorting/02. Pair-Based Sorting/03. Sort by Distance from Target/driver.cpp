#include <bits/stdc++.h>
#include "solution.cpp"

using namespace std;

struct Color {
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string RESET;
    static const string BOLD;
};

const string Color::RED    = "\033[31m";
const string Color::GREEN  = "\033[32m";
const string Color::YELLOW = "\033[33m";
const string Color::RESET  = "\033[0m";
const string Color::BOLD   = "\033[1m";

struct TestCase {
    vector<int> arr;
    int k;
    vector<int> expected;
};

class ResultFormatter {
public:
    static string vectorToString(const vector<int>& v) {
        string s = "[";
        for (int i = 0; i < (int)v.size(); i++) {
            s += to_string(v[i]);
            if (i + 1 < (int)v.size()) s += ",";
        }
        return s + "]";
    }
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {10, 5, 3, 9, 2}, 6, {5, 3, 9, 2, 10} },
            { {1, 2, 3, 4, 5}, 3, {3, 2, 4, 1, 5} },
            { {-10, 0, 10}, 0, {0, -10, 10} },
            { {1, 1, 1}, 5, {1, 1, 1} },
            { {100, 200, 300}, 250, {200, 300, 100} },
            { {5, 10, 15}, 10, {10, 5, 15} },
            { {-5, 5}, 0, {-5, 5} }, // same distance, -5 < 5
            { {10, -10}, 0, {-10, 10} },
            { {1, 2, 3}, 0, {1, 2, 3} },
            { {1, 2, 3}, 10, {3, 2, 1} },
            { {10, 20, 30, 40}, 25, {20, 30, 10, 40} },
            { {2147483647, -2147483648}, 0, {2147483647, -2147483648} }, // |2^31-1| vs |2^31|
            { {10, 10, 20, 20}, 15, {10, 10, 20, 20} },
            { {0, -1, 1, -2, 2}, 0, {0, -1, 1, -2, 2} },
            { {100, -100, 50, -50}, 25, {50, 0, 100, -50, -100} } // wait, 0 is not in input
        };
        
        // correcting case 15
        cases[14] = { {100, -100, 50, -50}, 25, {50, -50, 100, -100} };
        // |50-25|=25, |-50-25|=75, |100-25|=75, |-100-25|=125
        // Sorted: 50, then (-50 and 100 because -50 < 100), then -100

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Distance from Target..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            vector<int> result = sol.sortByDistance(tc.arr, tc.k);

            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();

            if (result == tc.expected) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::YELLOW << "Input: arr=" << ResultFormatter::vectorToString(tc.arr) << ", k=" << tc.k << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: " << ResultFormatter::vectorToString(tc.expected) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: " << ResultFormatter::vectorToString(result) << Color::RESET << "\n";
            }

            if (!logs.empty()) {
                cout << Color::YELLOW << "   Logs:" << Color::RESET << "\n";
                stringstream logStream(logs);
                string line;
                while (getline(logStream, line)) cout << "     " << line << "\n";
            }
        }

        cout << "\n";
        printSummary(passedCount, totalCount);
    }

private:
    void printSummary(int passedCount, int totalCount) {
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
        if (passedCount == totalCount) {
            cout << Color::GREEN << Color::BOLD
                 << "  ALL TESTS PASSED! (" << passedCount << "/" << totalCount << ")"
                 << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD
                 << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)"
                 << Color::RESET << "\n";
        }
        cout << Color::BOLD << "=======================================" << Color::RESET << "\n";
    }
};

int main() {
    TestRunner runner;
    runner.run();
    return 0;
}
