#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int maxRootToLeafSum(TreeNode *root) {
    int mx = numeric_limits<int>::min();
    if(!root->left and !root->right) return root->val;
    queue<pair<TreeNode *, int>> q;
    q.push({root, root->val});

    while (!q.empty()) {
      int len = q.size();
      while (len--) {
        auto [node, sum] = q.front();
        q.pop();

        if (!node->left and !node->right) {
          mx = max(mx, sum);
        }

        if (node->left) {
          q.push({node->left, sum + node->left->val});
        }
        if (node->right) {
          q.push({node->right, sum + node->right->val});
        }
      }
    }

    return mx;
  }
};
