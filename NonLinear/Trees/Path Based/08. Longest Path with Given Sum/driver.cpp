#include <bits/stdc++.h>
#include "Solution.cpp"
using namespace std;

struct Color {
    static const string RED;
    static const string GREEN;
    static const string YELLOW;
    static const string CYAN;
    static const string RESET;
    static const string BOLD;
};
const string Color::RED = "\033[31m";
const string Color::GREEN = "\033[32m";
const string Color::YELLOW = "\033[33m";
const string Color::CYAN = "\033[36m";
const string Color::RESET = "\033[0m";
const string Color::BOLD = "\033[1m";


TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -100000) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != -100000) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -100000) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

struct TestCase {
    vector<int> nodes;
    int target;
    int expected;
};
class TestRunner {
public:
    template<typename T>
    void print(const T& val) {
        if constexpr (is_same_v<T, vector<int>>) {
            cout << "[";
            for(int i=0; i<val.size(); i++) {
                if(val[i] == -100000) cout << "null";
                else cout << val[i];
                cout << (i == val.size()-1 ? "" : ", ");
            }
            cout << "]";
        } else {
            cout << val;
        }
    }

    void run() {
        vector<TestCase> cases = {
            { {1,2,3,1,1,1,1}, 3, 2 },
            { {0,0,0,0,0,0,0}, 0, 3 },
            { {5,4,8,11,-100000,13,4}, 9, 2 },
            { {1,1,1,1,1}, 2, 2 },
            { {1,1,1,1,1}, 3, 3 },
            { {10,-5,5,1,2,-1,3}, 5, 2 }, // 10-5
            { {1,2,3}, 6, 0 },
            { {1}, 1, 1 },
            { {}, 5, 0 },
            { {1,2,3,4,5,6,7}, 10, 3 },
            { {1,2,3,4,5,6,7}, 15, 0 },
            { {1,1,1,1,1,1,1}, 4, 0 },
            { {-1,-1,-1}, -2, 2 },
            { {10,5,-3,3,2,-100000,11,3,-2,-100000,1}, 8, 3 },
            { {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}, 15, 4 }
        };
        Solution sol;
        int passed = 0;
        cout << Color::BOLD << "Running 15 Tests for Longest Path with Given Sum..." << Color::RESET << "\n\n";
        for(int i=0; i<cases.size(); i++) {
            TreeNode* root = buildTree(cases[i].nodes);
            int res = sol.longestPathWithSum(root, cases[i].target);
            if(res == cases[i].expected) {
                cout << Color::GREEN << "✓ Test " << i+1 << " Passed" << Color::RESET << "\n";
                passed++;
            } else {
                cout << Color::RED << "✗ Test " << i+1 << " Failed" << Color::RESET << "\n";
                cout << Color::CYAN << "    [LOG] Input:    nodes: " << Color::RESET; print(cases[i].nodes); cout << Color::CYAN << ", target: " << Color::RESET << cases[i].target << "\n";
                cout << Color::CYAN << "    [LOG] Expected: " << Color::RESET << cases[i].expected << "\n";
                cout << Color::CYAN << "    [LOG] Got:      " << Color::RESET << res << "\n\n";
            }
        }
        cout << "\n";
        printSummary(passed, cases.size());
    }

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
int main() { TestRunner().run(); return 0; }
