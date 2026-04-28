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
  int maxEvenPathLength(TreeNode *root) {
    int mx = INT_MIN;

    if(!root or root->val % 2 != 0) return 0;
    
    function<void(TreeNode *, int)> sol = [&](TreeNode *node, int lev) -> void {
      if (!node)
        return;

      lev += 1;

      if (!node->left and !node->right and node->val % 2 == 0) {
        mx = max(mx, lev);
        return;
      }

      if (node->left and node->left->val % 2 == 0) {
        sol(node->left, lev);
      }

      if (node->right and node->right->val % 2 == 0) {
        sol(node->right, lev);
      }
    };
    sol(root, 0);
    return mx;
  }
};
