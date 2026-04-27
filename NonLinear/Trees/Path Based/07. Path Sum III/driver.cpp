#include <bits/stdc++.h>
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
    void run() {
        vector<TestCase> cases = {
            { {10,5,-3,3,2,-100000,11,3,-2,-100000,1}, 8, 3 },
            { {5,4,8,11,-100000,13,4,7,2,-100000,-100000,5,1}, 22, 3 },
            { {1,2,3}, 3, 2 },
            { {1,2,3}, 5, 0 },
            { {1,1,1,1,1,1,1}, 2, 6 },
            { {1}, 1, 1 },
            { {1}, 0, 0 },
            { {}, 10, 0 },
            { {0,0,0}, 0, 5 }, // Root, L, R, Root-L, Root-R
            { {1,-2,-3}, -1, 1 },
            { {1,-2,-3}, -2, 2 },
            { {1000000,1000000,1000000}, 2000000, 2 },
            { {1,2,3,4,5}, 3, 2 }, // 1->2, 3
            { {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}, 7, 3 },
            { {1,2,3,4,5,6,7}, 10, 2 }
        };
        Solution sol;
        int passed = 0;
        cout << Color::BOLD << "Running 15 Tests for Path Sum III..." << Color::RESET << "\n\n";
        for(int i=0; i<cases.size(); i++) {
            TreeNode* root = buildTree(cases[i].nodes);
            int res = sol.pathSum(root, cases[i].target);
            if(res == cases[i].expected) {
                cout << Color::GREEN << "✓ Test " << i+1 << " Passed" << Color::RESET << "\n";
                passed++;
            } else {
                cout << Color::RED << "✗ Test " << i+1 << " Failed (Got " << res << ", Expected " << cases[i].expected << ")" << Color::RESET << "\n";
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
