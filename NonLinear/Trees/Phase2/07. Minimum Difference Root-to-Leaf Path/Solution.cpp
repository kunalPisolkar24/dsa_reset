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

    function<int(TreeNode *, int, int)> sol = [&](TreeNode *node, int mx,
                                                  int mn) -> int {
      if (!node)
        return INT_MAX;

      mx = max(mx, node->val);
      mn = min(mn, node->val);

      if (!node->left and !node->right) {
        return mx - mn;
      }

      return min(sol(node->left, mx, mn), sol(node->right, mx, mn));
    };

    return sol(root, INT_MIN, INT_MAX);
  }
};
