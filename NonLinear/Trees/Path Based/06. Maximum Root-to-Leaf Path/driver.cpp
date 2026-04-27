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
    int expectedSum;
};
class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {1,2,3}, 4 },
            { {5,4,8,11,-100000,13,4,7,2,-100000,-100000,-100000,1}, 27 },
            { {-10,9,20,-100000,-100000,15,7}, 25 },
            { {1}, 1 },
            { {1,2}, 3 },
            { {1,-100000,2}, 3 },
            { {1,2,3,4,5,6,7}, 11 },
            { {-1,-2,-3}, -3 },
            { {10,5,15,3,7,12,18}, 43 },
            { {1,2,2,3,4,4,3}, 7 },
            { {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}, 26 },
            { {0,0,0}, 0 },
            { {100,-50,-20,10,20,30,40}, 120 },
            { {1,-2,-3,-4,-5,-6,-7}, -5 },
            { {5,3,8,-100000,-100000,7}, 20 }
        };
        Solution sol;
        int passed = 0;
        cout << Color::BOLD << "Running 15 Tests for Maximum Root-to-Leaf Path..." << Color::RESET << "\n\n";
        for(int i=0; i<cases.size(); i++) {
            TreeNode* root = buildTree(cases[i].nodes);
            vector<int> res = sol.maxPath(root);
            int sum = 0;
            for(int x : res) sum += x;
            if(sum == cases[i].expectedSum) {
                cout << Color::GREEN << "✓ Test " << i+1 << " Passed" << Color::RESET << "\n";
                passed++;
            } else {
                cout << Color::RED << "✗ Test " << i+1 << " Failed (Got Sum " << sum << ", Expected Sum " << cases[i].expectedSum << ")" << Color::RESET << "\n";
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
