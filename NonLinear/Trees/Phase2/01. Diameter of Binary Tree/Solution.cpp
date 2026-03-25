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
  int diameterOfBinaryTree(TreeNode *root) {
    function<int(TreeNode *)> height = [&](TreeNode *node) -> int {
      if (!node)
        return 0;
      return 1 + max(height(node->left), height(node->right));
    };

    int mx = numeric_limits<int>::min();
    function<void(TreeNode *)> sol = [&](TreeNode *node) -> void {
      if (!node)
        return;
      mx = max(mx, height(node->left) + height(node->right));
      sol(node->left);
      sol(node->right);
    };

    sol(root);
    return mx;
  }
};
