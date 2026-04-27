#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int pathSum(TreeNode *root, int targetSum) {
    int count = 0;

    function<void(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> void {
      if (!node)
        return;

      if (sum - node->val == 0) {
        count++;
      }
      sol(node->left, sum - node->val);
      sol(node->right, sum - node->val);
    };

    function<void(TreeNode *)> sol1 = [&](TreeNode *node) -> void {
      if (!node)
        return;
      sol(node, targetSum);
      sol1(node->left);
      sol1(node->right);
    };

    sol1(root);
    return count;
  }
};
