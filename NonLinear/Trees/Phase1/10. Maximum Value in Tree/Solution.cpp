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
  int findMax(TreeNode *root) {
    int mx = numeric_limits<int>::min();
    function<void(TreeNode *)> sol = [&](TreeNode *root) -> void {
      if (!root)
        return;
      mx = max(root->val, mx);
      sol(root->left);
      sol(root->right);
    };
    sol(root);
    return mx;
  }
};
