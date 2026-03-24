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
  int checkHeight(TreeNode *root) {
    int f = true;

    function<int(TreeNode *)> sol = [&](TreeNode *node) -> int {
      if (!node or !f)
        return 0;

      int left = sol(node->left);
      int right = sol(node->right);

      if (abs(right - left) > 1) {
        f = false;
        return 0;
      }

      return 1 + max(left, right);
    };

    int h = sol(root);
    return (f ? h : -1);
    return -1;
  }
};
