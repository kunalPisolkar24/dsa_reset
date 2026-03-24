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
    bool res = false;

    function<bool(TreeNode *)> sol = [&](TreeNode *node) -> bool {
      if (!node)
        return 0;
      int left = node->left ? node->left->val : 0;
      int right = node->right ? node->right->val : 0;
      if ((left + right) == node->val) {
        return true;
      }

      return sol(node->left) or sol(node->right);
    };

    return sol(root);
  }
};
