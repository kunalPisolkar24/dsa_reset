#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int countPathSum(TreeNode *root, int targetSum) {
    function<int(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> int {
      if (!node)
        return 0;

      if (!node->left and !node->right) {
        return (sum - node->val == 0) ? 1 : 0;
      }

      return sol(node->left, sum - node->val) +
             sol(node->right, sum - node->val);
    };

    return sol(root, targetSum);
  }
};
