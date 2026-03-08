#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

struct TestCase {
    int n;
    vector<vector<int>> edges;
    vector<int> expected;
};

int main() {
    Solution sol;
    vector<TestCase> cases = {
    { 8, {{3, 4}, {3, 7}, {2, 3}, {6, 7}, {4, 5}, {1, 7}, {0, 2}, {1, 6}, {1, 3}}, {0, 2, 3, 1, 6, 7, 4, 5} },
    { 3, {}, {0, 1, 2} },
    { 18, {{3, 4}}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17} },
    { 4, {{0, 1}}, {0, 1, 2, 3} },
    { 12, {{4, 9}, {1, 8}, {8, 10}, {4, 5}, {6, 9}, {8, 11}}, {0, 1, 8, 10, 11, 2, 3, 4, 5, 9, 6, 7} },
    { 6, {}, {0, 1, 2, 3, 4, 5} },
    { 9, {{0, 7}, {3, 8}, {1, 4}, {0, 2}, {2, 5}}, {0, 2, 5, 7, 1, 4, 3, 8, 6} },
    { 14, {{9, 13}, {11, 13}, {6, 8}, {0, 3}, {7, 13}, {8, 13}, {6, 7}, {5, 10}, {0, 5}}, {0, 3, 5, 10, 1, 2, 4, 6, 7, 13, 8, 9, 11, 12} },
    { 2, {}, {0, 1} },
    { 14, {{4, 13}, {3, 4}, {0, 3}, {4, 12}, {3, 10}, {0, 9}, {5, 13}, {11, 12}, {7, 12}, {3, 9}, {0, 8}}, {0, 3, 4, 12, 7, 11, 13, 5, 9, 10, 8, 1, 2, 6} },
    { 4, {{0, 1}, {1, 3}, {0, 2}, {2, 3}}, {0, 1, 3, 2} },
    { 6, {{4, 5}, {2, 5}, {0, 4}}, {0, 4, 5, 2, 1, 3} },
    { 2, {}, {0, 1} },
    { 9, {}, {0, 1, 2, 3, 4, 5, 6, 7, 8} },
    { 8, {{1, 2}, {3, 4}, {4, 6}, {1, 4}, {2, 6}, {3, 6}, {1, 3}, {4, 7}}, {0, 1, 2, 6, 3, 4, 7, 5} }
};

    
    int passed = 0;
    for (int i = 0; i < cases.size(); i++) {
        TestCase tc = cases[i];
        vector<int> result = sol.dfsTraversal(tc.n, tc.edges);
        if (result == tc.expected) {
            cout << "Test " << i + 1 << ": PASSED\n";
            passed++;
        } else {
            cout << "Test " << i + 1 << ": FAILED\n";
            cout << "Expected: ["; for(int x:tc.expected) cout<<x<<","; cout<<"] | Got: ["; for(int x:result) cout<<x<<","; cout<<"]\n";
        }
    }
    
    cout << "\nResult: " << passed << " / " << cases.size() << " tests passed.\n";
    return 0;
}
