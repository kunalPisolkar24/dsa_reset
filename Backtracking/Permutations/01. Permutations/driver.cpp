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
    vector<int> nums;
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
            { {1,2,3}, {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}} },
            { {0,1}, {{0,1},{1,0}} },
            { {1}, {{1}} },
            { {1,2,3,4}, { /* Too many to list, will verify by size and uniqueness */ } },
            { {10, -5}, { {10,-5}, {-5, 10} } },
            { {1,2,3,4,5}, {} },
            { {1,2,3,4,5,6}, {} }
        };
        
        // Let's refine the test runner to handle large factorial sets
        // and add more specific small cases.
        cases = {
            { {1,2,3}, {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}} },
            { {0,1}, {{0,1},{1,0}} },
            { {1}, {{1}} },
            { {10, -5}, {{10,-5}, {-5,10}} },
            { {1,2,3,4}, {} }, // Size 24
            { {1,2,3,4,5}, {} }, // Size 120
            { {1,2,3,4,5,6}, {} }, // Size 720
            { {5, 10, 15}, {{5,10,15},{5,15,10},{10,5,15},{10,15,5},{15,5,10},{15,10,5}} },
            { {2,4}, {{2,4},{4,2}} },
            { {1,2,3,4,5}, {} },
            { {1,10}, {{1,10},{10,1}} },
            { {22,33}, {{22,33},{33,22}} },
            { {1,2,3,4,5}, {} },
            { {1,5,3}, {{1,5,3},{1,3,5},{5,1,3},{5,3,1},{3,1,5},{3,5,1}} },
            { {11,22,33}, {{11,22,33},{11,33,22},{22,11,33},{22,33,11},{33,11,22},{33,22,11}} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Permutations..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];

            stringstream buffer;
            streambuf* oldBuf = cout.rdbuf(buffer.rdbuf());

            vector<vector<int>> result = sol.permute(tc.nums);

            cout.rdbuf(oldBuf);
            string logs = buffer.str();

            // Verification logic:
            // 1. Correct number of permutations (n!)
            // 2. All permutations are unique
            // 3. If expected is provided, it matches perfectly
            
            long long expectedSize = 1;
            for(int j=1; j<=(int)tc.nums.size(); j++) expectedSize *= j;

            bool sizeMatch = (result.size() == (size_t)expectedSize);
            
            set<vector<int>> uniqueResults(result.begin(), result.end());
            bool uniqueness = (uniqueResults.size() == result.size());
            
            bool expectedMatch = true;
            if (!tc.expected.empty()) {
                vector<vector<int>> sortedResult = result;
                vector<vector<int>> sortedExpected = tc.expected;
                sort(sortedResult.begin(), sortedResult.end());
                sort(sortedExpected.begin(), sortedExpected.end());
                expectedMatch = (sortedResult == sortedExpected);
            }

            bool passed = sizeMatch && uniqueness && expectedMatch;

            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                if (!sizeMatch) cout << "     " << Color::RED << "Size Mismatch: Expected " << expectedSize << ", Got " << result.size() << Color::RESET << "\n";
                if (!uniqueness) cout << "     " << Color::RED << "Duplicates found in result!" << Color::RESET << "\n";
                if (!expectedMatch) {
                    cout << "     " << Color::RED << "Expected: " << ResultFormatter::matrixToString(tc.expected) << Color::RESET << "\n";
                    cout << "     " << Color::RED << "Got     : " << ResultFormatter::matrixToString(result) << Color::RESET << "\n";
                }
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
