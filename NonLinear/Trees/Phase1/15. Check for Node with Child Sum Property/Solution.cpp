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
  bool hasChildSum(TreeNode *root) {
    if (!root)
      return false;

    if (!root->left and !root->right)
      return false;

    int left = root->left ? root->left->val : 0;
    int right = root->right ? root->right->val : 0;

    if (root->val == (left + right))
      return true;

    return hasChildSum(root->left) or hasChildSum(root->right);
  }
};
