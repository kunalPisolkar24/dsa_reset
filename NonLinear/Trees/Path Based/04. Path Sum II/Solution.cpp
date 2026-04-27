#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<int> temp;
    vector<vector<int>> ans;
    function<void(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> void {
      if (!node)
        return;

      temp.push_back(node->val);

      if (!node->left and !node->right) {
        if (sum - node->val == 0) {
          ans.push_back(temp);
          temp.pop_back();
          return;
        }
      } else {
        sol(node->left, sum - node->val);
        sol(node->right, sum - node->val);
      }
      temp.pop_back();
    };
    sol(root, targetSum);
    return ans;
  }
};
