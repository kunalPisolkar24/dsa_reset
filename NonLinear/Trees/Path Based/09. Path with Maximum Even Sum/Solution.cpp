#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxEvenPathSum(TreeNode *root) {
    int mx = INT_MIN;
    function<void(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> void {
      if (!node)
        return;
      sum += node->val;
      if (!node->left and !node->right) {
        if ((sum & 1) == 0 and sum > mx) {
          mx = sum;
        }
        return;
      } else {
        sol(node->left, sum);
        sol(node->right, sum);
      }
    };
    sol(root, 0);
    return mx == INT_MIN ? -1 : mx;
  }
};
