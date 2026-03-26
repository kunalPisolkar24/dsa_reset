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
    int target;
    int expected;
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
            { {5, 3, 10, 1, -100000, 7}, 7, 2 },
            { {1, 2, 3}, 5, -1 },
            { {10, 5, 15}, 8, 1 },
            { {1, 2, 3, 4, 5, 6, 7}, 7, 3 },
            { {100, 10, 200, 5, 150, 250}, 150, 2 },
            { {1, 1, 1, 1, 1, 1, 1}, 1, 1 },
            { {0, 0, 0}, 0, 1 },
            { {10, -10, 20}, -5, 1 },
            { {1, 2, -100000, 3, -100000, 4}, 4, 4 },
            { {8, 4, 12, 2, 6, 10, 14}, 14, 3 },
            { {8, 4, 12, 2, 6, 10, 14}, 20, -1 },
            { {10, -100000, 20, -100000, 30}, 25, 3 },
            { {5, 1, 10, -100000, -100000, 2, -100000}, 2, 1 },
            { {100}, 100, 1 },
            { {1}, 1, 1 },
            { {100}, 101, -1 }
        };

        Solution sol;
        int passedCount = 0;
        int totalCount = cases.size();

        cout << Color::BOLD << "Running " << totalCount << " Tests for Minimum Depth to a Node with Value >= X..." << Color::RESET << "\n\n";

        for (int i = 0; i < totalCount; i++) {
            TestCase tc = cases[i];
            TreeNode* root = buildTree(tc.nodes);
            
            stringstream buffer;
            streambuf* oldCoutBuf = cout.rdbuf(buffer.rdbuf());
            
            auto result = sol.minDepthGE(root, tc.target);
            
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
                cout << "     " << Color::RED << "Expected: " << tc.expected << Color::RESET << "\n";
                cout << "     " << Color::RED << "Got: " << result << Color::RESET << "\n";
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
