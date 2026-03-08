#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

struct TestCase {
    int n;
    vector<vector<int>> edges;
    int expected;
};

int main() {
    Solution sol;
    vector<TestCase> cases = {
    { 13, {}, 0 },
    { 20, {{4, 11}}, 0 },
    { 23, {{6, 12}, {4, 6}, {14, 19}, {8, 18}, {17, 18}, {19, 21}, {2, 11}, {1, 9}, {10, 15}, {2, 14}, {1, 18}, {7, 16}, {6, 17}, {5, 12}, {4, 20}, {0, 1}, {2, 7}, {0, 16}, {6, 10}, {6, 19}, {5, 8}, {9, 12}, {19, 22}, {13, 15}}, 13 },
    { 11, {{7, 10}, {0, 3}, {3, 10}, {7, 9}, {6, 7}, {1, 7}, {5, 10}, {4, 8}, {0, 5}, {0, 8}, {2, 5}}, 4 },
    { 5, {{2, 3}, {2, 4}}, 0 },
    { 22, {{4, 10}, {1, 21}, {18, 19}, {0, 15}, {6, 9}}, 1 },
    { 12, {{5, 11}, {1, 4}}, 0 },
    { 17, {{1, 12}, {1, 5}, {15, 16}, {10, 16}, {11, 15}}, 0 },
    { 2, {}, 0 },
    { 18, {{10, 11}, {3, 14}, {13, 16}, {8, 16}, {3, 10}, {2, 3}, {2, 6}}, 0 },
    { 5, {{0, 2}, {1, 4}}, 1 },
    { 13, {{1, 6}, {1, 8}, {1, 9}, {1, 10}}, 0 },
    { 9, {{3, 4}, {5, 8}, {6, 7}, {4, 5}, {0, 5}, {4, 8}, {1, 6}, {3, 5}}, 4 },
    { 2, {}, 0 },
    { 8, {{0, 1}, {2, 7}, {0, 3}, {5, 7}, {3, 6}, {4, 7}}, 2 }
};

    
    int passed = 0;
    for (int i = 0; i < cases.size(); i++) {
        TestCase tc = cases[i];
        int result = sol.longestDFSChain(tc.n, tc.edges);
        if (result == tc.expected) {
            cout << "Test " << i + 1 << ": PASSED\n";
            passed++;
        } else {
            cout << "Test " << i + 1 << ": FAILED\n";
            cout << "Expected: " << tc.expected << " | Got: " << result << "\n";
        }
    }
    
    cout << "\nResult: " << passed << " / " << cases.size() << " tests passed.\n";
    return 0;
}
