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
  int minDepthGE(TreeNode *root, int x) {
    function<int(TreeNode *)> sol = [&](TreeNode *node) -> int {
      if (!node)
        return INT_MAX;

      if (node->val >= x)
        return 1;

      int left = sol(node->left);
      int right = sol(node->right);

      int best = min(left, right);
      if (best == INT_MAX)
        return INT_MAX;
      return best + 1;
    };
    int mn = sol(root);
    return (mn == INT_MAX ? -1 : mn);
  }
};
