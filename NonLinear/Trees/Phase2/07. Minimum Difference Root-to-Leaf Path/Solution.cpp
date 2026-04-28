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
  int minDiffPath(TreeNode *root) {
    int global_min = INT_MAX;
    function<void(TreeNode *, int, int)> sol = [&](TreeNode *node, int mx,
                                                   int mn) -> void {
      if (!node)
        return;

      mx = max(mx, node->val);
      mn = min(mn, node->val);

      if (!node->left and !node->right) {
        global_min = min(global_min, mx - mn);
        return;
      }
      sol(node->left, mx, mn);
      sol(node->right, mx, mn);
    };
    sol(root, INT_MIN, INT_MAX);
    return global_min;
  }
};
