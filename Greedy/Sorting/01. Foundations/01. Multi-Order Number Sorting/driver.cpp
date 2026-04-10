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
    vector<int> expectedAsc;
    vector<int> expectedDesc;
    vector<int> expectedDist;
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
            // Case 1: Simple small array
            { {7, 2, 9, 1, 5}, 5, {1, 2, 5, 7, 9}, {9, 7, 5, 2, 1}, {5, 7, 2, 1, 9} },
            // Case 2: Negative and zero
            { {10, -5, 0, 5}, 0, {-5, 0, 5, 10}, {10, 5, 0, -5}, {0, -5, 5, 10} },
            // Case 3: Duplicates
            { {1, 1, 1}, 2, {1, 1, 1}, {1, 1, 1}, {1, 1, 1} },
            // Case 4: Single element
            { {42}, 10, {42}, {42}, {42} },
            // Case 5: Two elements
            { {10, 20}, 15, {10, 20}, {20, 10}, {10, 20} },
            // Case 6: Target k is already in array
            { {1, 2, 3, 4, 5}, 3, {1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, {3, 2, 4, 1, 5} },
            // Case 7: All same negative
            { {-5, -5, -5}, -5, {-5, -5, -5}, {-5, -5, -5}, {-5, -5, -5} },
            // Case 8: Strict descending
            { {10, 8, 6, 4, 2}, 5, {2, 4, 6, 8, 10}, {10, 8, 6, 4, 2}, {4, 6, 2, 8, 10} },
            // Case 9: Large values
            { {1000000000, -1000000000, 0}, 0, {-1000000000, 0, 1000000000}, {1000000000, 0, -1000000000}, {0, -1000000000, 1000000000} },
            // Case 10: Tied distances
            { {2, 8}, 5, {2, 8}, {8, 2}, {2, 8} },
            // Case 11: Tied distances
            { {11, 9}, 10, {9, 11}, {11, 9}, {9, 11} },
            // Case 12: k far left
            { {10, 20, 30}, 0, {10, 20, 30}, {30, 20, 10}, {10, 20, 30} },
            // Case 13: k far right
            { {10, 20, 30}, 100, {10, 20, 30}, {30, 20, 10}, {30, 20, 10} },
            // Case 14: Many elements
            { {3, 1, 4, 1, 5, 9, 2}, 5, {1, 1, 2, 3, 4, 5, 9}, {9, 5, 4, 3, 2, 1, 1}, {5, 4, 3, 2, 1, 1, 9} },
            // Case 15: Negative k
            { {-10, -20, -30}, -15, {-30, -20, -10}, {-10, -20, -30}, {-20, -10, -30} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount  = cases.size();

        cout << Color::BOLD << "Running " << totalCount
             << " Tests for Multi-Order Sorting..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase& tc = cases[i];
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());

            vector<int> resAsc = sol.sortAscending(tc.arr);
            vector<int> resDesc = sol.sortDescending(tc.arr);
            vector<int> resDist = sol.sortByDistance(tc.arr, tc.k);

            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();

            bool passed = (resAsc == tc.expectedAsc && resDesc == tc.expectedDesc && resDist == tc.expectedDist);

            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::YELLOW << "Input: " << Color::RESET << "arr=" << ResultFormatter::vectorToString(tc.arr) << ", k=" << tc.k << "\n";
                
                if (resAsc != tc.expectedAsc) {
                    cout << "     " << Color::RED << "Ascending  - Expected: " << ResultFormatter::vectorToString(tc.expectedAsc) 
                         << ", Got: " << ResultFormatter::vectorToString(resAsc) << Color::RESET << "\n";
                }
                if (resDesc != tc.expectedDesc) {
                    cout << "     " << Color::RED << "Descending - Expected: " << ResultFormatter::vectorToString(tc.expectedDesc) 
                         << ", Got: " << ResultFormatter::vectorToString(resDesc) << Color::RESET << "\n";
                }
                if (resDist != tc.expectedDist) {
                    cout << "     " << Color::RED << "Distance   - Expected: " << ResultFormatter::vectorToString(tc.expectedDist) 
                         << ", Got: " << ResultFormatter::vectorToString(resDist) << Color::RESET << "\n";
                }
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
