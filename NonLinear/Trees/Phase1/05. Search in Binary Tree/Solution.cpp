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
  bool searchNode(TreeNode *root, int val) {
    if (!root)
      return false;
    if (root->val == val)
      return true;
    return searchNode(root->left, val) || searchNode(root->right, val);
  }
};
