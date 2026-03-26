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
  int minCostPath(TreeNode *root) {
    if (!root)
      return 0;
    if (!root->left and !root->right) {
      return root->val;
    }

    if (!root->left) {
      return root->val + minCostPath(root->right);
    }
    if (!root->right) {
      return root->val + minCostPath(root->left);
    }

    return root->val + min(minCostPath(root->left), minCostPath(root->right));
  }
};
