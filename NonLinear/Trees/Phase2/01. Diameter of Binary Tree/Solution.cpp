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
    int mx = 0;
    function<int(TreeNode *)> sol = [&](TreeNode *node) -> int {
      if (!node)
        return 0;
      int left = sol(node->left);
      int right = sol(node->right);
      mx = max(mx, left + right);
      return 1 + max(left, right);
    };

    sol(root);
    return mx;
  }
};
