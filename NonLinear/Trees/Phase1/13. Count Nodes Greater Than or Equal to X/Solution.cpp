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
  int countNodesGE(TreeNode *root, int x) {
    if (!root)
      return 0;
    int left = countNodesGE(root->left, x);
    int right = countNodesGE(root->right, x);
    return (root->val >= x) + left + right;
  }
};
