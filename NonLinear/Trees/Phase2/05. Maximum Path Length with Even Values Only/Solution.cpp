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

    function<int(TreeNode *)> sol = [&](TreeNode *node) -> int {
      if (!node or node->val % 2 != 0)
        return 0;

      int left = sol(node->left);
      int right = sol(node->right);

      if (left == 0 and right == 0)
        return 1;
      return 1 + max(left, right);
    };
    return sol(root);
  }
};
