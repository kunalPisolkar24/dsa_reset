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

struct TestCase {
    vector<int> nodes;
    
    vector<int> expected;
};

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

class TestRunner {
public:
    void run() {
        vector<TestCase> cases = {
            { {42}, {42} },
            { {1}, {1} },
            { {1, 2, 3}, {2, 1, 3} },
            { {1, 2, 3, 4, 5, 6, 7}, {4, 2, 5, 1, 6, 3, 7} },
            { {1, 2, -100000, 3, -100000, 4}, {4, 3, 2, 1} },
            { {1, -100000, 2, -100000, 3, -100000, 4}, {1, 2, 3, 4} },
            { {1, 2, 3, 4, -100000, -100000, 5}, {4, 2, 1, 3, 5} },
            { {1, 2, 2, 3, 4, 4, 3}, {3, 2, 4, 1, 4, 2, 3} },
            { {1, 2, 2, -100000, 3, -100000, 3}, {2, 3, 1, 2, 3} },
            { {10, 5, 15, 3, 7, 12, 18}, {3, 5, 7, 10, 12, 15, 18} },
            { {-10, 9, 20, -100000, -100000, 15, 7}, {9, -10, 15, 20, 7} },
            { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15} },
            { {3, 9, 20, -100000, -100000, 15, 7}, {9, 3, 15, 20, 7} },
            { {1, -100000, 2, 3}, {1, 3, 2} },
            { {5, 4, 8, 11, -100000, 13, 4, 7, 2, -100000, -100000, 5, 1}, {7, 11, 2, 4, 5, 13, 8, 5, 4, 1} }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Inorder Traversal (Recursive)..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            TreeNode* root = buildTree(tc.nodes);
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.inorderTraversal(root);
            
            cout.rdbuf(oldCoutBuf);
            string logs = buffer.str();
            
            bool passed = (result == tc.expected);
            
            if (passed) {
                cout << Color::GREEN << "✓ Test " << i + 1 << " Passed" << Color::RESET << "\n";
                passedCount++;
            } else {
                cout << Color::RED << "✗ Test " << i + 1 << " Failed" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Input Nodes: [";
                for(int j=0; j<tc.nodes.size(); j++) {
                    if(tc.nodes[j] == -100000) cout << "null";
                    else cout << tc.nodes[j];
                    if(j < tc.nodes.size()-1) cout << ",";
                }
                cout << "]" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Expected: [";
                for(int j=0; j<tc.expected.size(); j++) cout << tc.expected[j] << (j == tc.expected.size()-1 ? "" : ",");
                cout << "]" << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: [";
                for(int j=0; j<result.size(); j++) cout << result[j] << (j == result.size()-1 ? "" : ",");
                cout << "]" << Color::RESET << "\n";
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
            cout << Color::GREEN << Color::BOLD << "  ALL TESTS PASSED! (" << passedCount << "/" << totalCount << ")" << Color::RESET << "\n";
            cout << Color::GREEN << "  (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧" << Color::RESET << "\n";
        } else {
            cout << Color::RED << Color::BOLD << "  TESTS FAILED (" << passedCount << "/" << totalCount << " passed)" << Color::RESET << "\n";
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
