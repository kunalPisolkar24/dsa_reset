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
    function<int(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> int {
      if (!node)
        return INT_MIN;

      sum += node->val;

      if (!node->left and !node->right) {
        return (sum % 2 == 0) ? sum : INT_MIN;
      }
      
      int left = sol(node->left, sum);
      int right = sol(node->right, sum);
      return max(left, right);
    };

    int res = sol(root, 0);
    return res == INT_MIN ? -1 : res;
  }
};
