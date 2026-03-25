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
    int mx = numeric_limits<int>::min();

    function<void(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> void {
      if (!node)
        return;
      if (!node->left and !node->right) {
        mx = max(mx, sum);
      }

      if (node->left) {
        sol(node->left, node->left->val + sum);
      }
      if (node->right) {
        sol(node->right, node->right->val + sum);
      }
    };

    sol(root, root->val);
    return mx;
  }
};
