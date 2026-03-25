#include <algorithm>
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
    if (!root->left and !root->right) {
      return root->val;
    }

    if (!root->left)
      return root->val + maxRootToLeafSum(root->right);

    if (!root->right)
      return root->val + maxRootToLeafSum(root->left);

    return root->val +
           max(maxRootToLeafSum(root->left), maxRootToLeafSum(root->right));
  }
};
