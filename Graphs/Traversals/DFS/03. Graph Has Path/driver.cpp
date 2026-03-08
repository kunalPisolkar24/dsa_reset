#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

struct TestCase {
    int n;
    vector<vector<int>> edges;
    int u;
    int v;
    bool expected;
};

int main() {
    Solution sol;
    vector<TestCase> cases = {
    { 14, {{9, 13}, {6, 11}, {6, 8}, {2, 6}, {3, 9}, {5, 12}, {0, 11}}, 9, 12, false },
    { 6, {{2, 4}, {2, 5}, {0, 5}}, 0, 4, true },
    { 3, {{1, 2}}, 0, 2, false },
    { 12, {{3, 4}, {1, 5}, {1, 8}, {0, 3}, {1, 4}, {0, 6}, {0, 11}, {8, 9}, {3, 9}, {4, 7}, {7, 8}, {3, 11}}, 0, 10, false },
    { 12, {{0, 1}, {3, 8}, {10, 11}, {6, 8}, {7, 9}, {4, 5}, {4, 8}, {1, 6}, {1, 3}, {8, 11}}, 8, 11, true },
    { 7, {{2, 4}, {0, 4}, {0, 5}}, 6, 5, false },
    { 14, {{4, 10}, {3, 8}, {1, 2}, {0, 4}, {4, 9}, {0, 13}, {5, 13}, {4, 5}, {8, 9}, {1, 10}, {0, 8}, {3, 5}}, 11, 0, false },
    { 19, {{0, 18}, {12, 16}, {11, 17}}, 2, 6, false },
    { 6, {}, 1, 4, false },
    { 19, {{4, 9}, {5, 7}, {4, 15}, {8, 9}, {9, 14}, {1, 6}, {2, 14}, {1, 15}, {6, 11}, {6, 17}, {5, 6}, {3, 6}, {3, 18}, {8, 11}, {8, 14}, {10, 14}, {6, 7}, {4, 7}, {3, 11}, {4, 10}, {8, 13}, {10, 16}}, 4, 11, true },
    { 19, {{4, 10}, {1, 12}, {5, 15}, {7, 10}, {7, 16}, {12, 16}, {0, 9}, {1, 14}, {10, 13}, {4, 11}, {10, 18}, {7, 8}}, 17, 0, false },
    { 17, {{2, 14}, {0, 7}, {0, 16}, {8, 13}, {5, 16}, {5, 12}, {0, 11}}, 16, 9, false },
    { 19, {{4, 16}, {2, 4}, {7, 10}, {6, 7}, {5, 16}, {6, 10}, {12, 14}}, 17, 14, false },
    { 2, {}, 1, 1, true },
    { 3, {{0, 2}}, 2, 1, false }
};

    
    int passed = 0;
    for (int i = 0; i < cases.size(); i++) {
        TestCase tc = cases[i];
        bool result = sol.hasPath(tc.n, tc.edges, tc.u, tc.v);
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
