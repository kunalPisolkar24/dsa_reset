#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int longestPathWithSum(TreeNode *root, int targetSum) {

    int mx = 0;

    function<void(TreeNode *, int, int)> sol2 = [&](TreeNode *node, int sum,
                                                    int count) -> void {
      if (!node)
        return;
      sum += node->val;
      count += 1;

      if (sum == targetSum) {
        mx = max(mx, count);
      }

      sol2(node->left, sum, count);
      sol2(node->right, sum, count);
    };

    function<void(TreeNode *)> sol = [&](TreeNode *node) -> void {
      if (!node)
        return;
      sol2(node, 0, 0);
      sol(node->left);
      sol(node->right);
    };

    sol(root);
    return mx;
  }
};
