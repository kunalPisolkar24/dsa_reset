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
    vector<int> candidates;
    int target;
    vector<vector<int>> expected;
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

    static string matrixToString(const vector<vector<int>>& m) {
        string s = "[";
        for (int i = 0; i < (int)m.size(); i++) {
            s += vectorToString(m[i]);
            if (i + 1 < (int)m.size()) s += ", ";
        }
        return s + "]";
    }
};

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {2,3,6,7}, 7, {{2,2,3}, {7}} },
            { {2,3,5}, 8, {{2,2,2,2}, {2,3,3}, {3,5}} },
            { {2}, 1, {} },
            { {1}, 1, {{1}} },
            { {1}, 2, {{1,1}} },
            { {2,4,6,8}, 8, {{2,2,2,2}, {2,2,4}, {2,6}, {4,4}, {8}} },
            { {3,5,7}, 10, {{3,3,4}, {3,7}, {5,5}} }, // Wait, 3+3+4 is not possible since 4 is not in candidates. 3+7=10, 5+5=10.
            { {10}, 10, {{10}} },
            { {2,3}, 5, {{2,3}} },
            { {2,3}, 6, {{2,2,2}, {3,3}} },
            { {1,2}, 4, {{1,1,1,1}, {1,1,2}, {2,2}} },
            { {5,10,15}, 20, {{5,5,5,5}, {5,5,10}, {10,10}, {5,15}} },
            { {2,7,11,15}, 3, {} },
            { {1,3,5,7}, 8, {{1,1,1,1,1,1,1,1}, {1,1,1,1,1,3}, {1,1,1,1,1,1,1,1}, {1,1,1,5}, {1,1,3,3}, {1,7}, {3,5}, {1,1,1,1,1,3}} } // This needs re-calc
        };
        
        // Let's refine case 14 and 7:
        cases[6] = { {3,5,7}, 10, {{3,7}, {5,5}} };
        cases[13] = { {1,2,5}, 5, {{1,1,1,1,1}, {1,1,1,2}, {1,2,2}, {5}} };
        cases.push_back({ {2,3,4}, 6, {{2,2,2}, {2,4}, {3,3}} }); // Case 15

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Combination Sum (Unlimited Usage)..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];

            stringstream buffer;
            streambuf* oldBuf = cout.rdbuf(buffer.rdbuf());

            vector<vector<int>> result = sol.combinationSum(tc.candidates, tc.target);

            cout.rdbuf(oldBuf);
            string logs = buffer.str();

            vector<vector<int>> sortedResult   = result;
            vector<vector<int>> sortedExpected = tc.expected;

            for (auto& v : sortedResult) sort(v.begin(), v.end());
            for (auto& v : sortedExpected) sort(v.begin(), v.end());
            sort(sortedResult.begin(),   sortedResult.end());
            sort(sortedExpected.begin(), sortedExpected.end());

            bool passed = (sortedResult == sortedExpected);

            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected (" << tc.expected.size() << "): "
                     << ResultFormatter::matrixToString(sortedExpected) << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got      (" << result.size() << "): "
                     << ResultFormatter::matrixToString(sortedResult) << Color::RESET << "\n";
            }

            if (!logs.empty()) {
                cout << Color::YELLOW << "   Logs:" << Color::RESET << "\n";
                stringstream logStream(logs);
                string line;
                while (getline(logStream, line)) {
                    cout << "     " << line << "\n";
                }
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
            cout << Color::GREEN << "  (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧" << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD
                 << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)"
                 << Color::RESET << "\n";
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
