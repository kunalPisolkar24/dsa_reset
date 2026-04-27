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
    int count = 0;
    function<void(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> void {
      if (!node)
        return;

      if (!node->left and !node->right) {
        if (sum - node->val == 0) {
          count++;
          return;
        }
      } else {
        sol(node->left, sum - node->val);
        sol(node->right, sum - node->val);
      }
    };
    
    sol(root, targetSum);
    return count;
  }
};
