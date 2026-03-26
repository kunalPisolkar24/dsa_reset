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
  int expected;
};

static const int NULL_NODE = -100000;

TreeNode *buildTree(const vector<int> &nodes) {
  if (nodes.empty() || nodes[0] == NULL_NODE)
    return nullptr;

  TreeNode *root = new TreeNode(nodes[0]);
  queue<TreeNode *> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < (int)nodes.size()) {
    TreeNode *cur = q.front();
    q.pop();

    if (i < (int)nodes.size() && nodes[i] != NULL_NODE) {
      cur->left = new TreeNode(nodes[i]);
      q.push(cur->left);
    }
    i++;

    if (i < (int)nodes.size() && nodes[i] != NULL_NODE) {
      cur->right = new TreeNode(nodes[i]);
      q.push(cur->right);
    }
    i++;
  }

  return root;
}

class TestRunner {
public:
  void run() {
    vector<TestCase> cases = {
        {{2}, 1},
        {{3}, 0},
        {{2, 4, 6}, 2},
        {{2, 3, 4}, 2},
        {{2, 4, 6, 8, NULL_NODE, NULL_NODE, 10}, 3},
        {{1, 2, 4, NULL_NODE, NULL_NODE, NULL_NODE, 6}, 0},
        {{2, 4, 7, NULL_NODE, 3, NULL_NODE, NULL_NODE}, 0},
        {{6, 2, 3, 1, 4, 2, 8}, 3},
        {{2, 4, 8, 6, NULL_NODE, NULL_NODE, 10}, 3},
        {{-2, 4, -3, -6, NULL_NODE, NULL_NODE, 8}, 3},
        {{4, 2, 6, NULL_NODE, 3, 5, NULL_NODE}, 0},
        {{2, 4, 6, 3, 8, 10, 12}, 3},
        {{2, 4, 6, NULL_NODE, NULL_NODE, 3, 8}, 3},
        {{10, 2, 4, NULL_NODE, NULL_NODE, 6, NULL_NODE}, 3},
        {{2, 4, 6, 8, 10, 3, 12, NULL_NODE, NULL_NODE, 14, NULL_NODE, NULL_NODE, NULL_NODE, 16, NULL_NODE}, 4},
    };

    Solution sol;
    int passedCount = 0;
    int totalCount = (int)cases.size();

    cout << Color::BOLD << "Running " << totalCount
         << " Tests for Maximum Path Length with Even Values Only..."
         << Color::RESET << "\n\n";

    for (int i = 0; i < totalCount; i++) {
      TestCase tc = cases[i];
      TreeNode *root = buildTree(tc.nodes);

      stringstream buffer;
      streambuf *oldCoutBuf = cout.rdbuf(buffer.rdbuf());

      int result = sol.maxEvenRootToLeafPathLength(root);

      cout.rdbuf(oldCoutBuf);
      string logs = buffer.str();

      bool passed = (result == tc.expected);
      if (passed) {
        cout << Color::GREEN << "PASS Test " << i + 1 << Color::RESET << "\n";
        passedCount++;
      } else {
        cout << Color::RED << "FAIL Test " << i + 1 << Color::RESET << "\n";
        cout << "     " << Color::RED << "Input Nodes: [";
        for (int j = 0; j < (int)tc.nodes.size(); j++) {
          if (tc.nodes[j] == NULL_NODE)
            cout << "null";
          else
            cout << tc.nodes[j];
          if (j + 1 < (int)tc.nodes.size())
            cout << ",";
        }
        cout << "]" << Color::RESET << "\n";
        cout << "     " << Color::RED << "Expected: " << tc.expected
             << Color::RESET << "\n";
        cout << "     " << Color::RED << "Got: " << result << Color::RESET
             << "\n";
      }

      if (!logs.empty()) {
        cout << Color::YELLOW << "   Logs:" << Color::RESET << "\n";
        stringstream logStream(logs);
        string line;
        while (getline(logStream, line))
          cout << "     " << line << "\n";
      }
    }

    cout << "\n";
    if (passedCount == totalCount) {
      cout << Color::GREEN << Color::BOLD << "ALL TESTS PASSED (" << passedCount
           << "/" << totalCount << ")" << Color::RESET << "\n";
    } else {
      cout << Color::RED << Color::BOLD << "TESTS FAILED (" << passedCount
           << "/" << totalCount << " passed)" << Color::RESET << "\n";
    }
  }
};

int main() {
  TestRunner runner;
  runner.run();
  return 0;
}

