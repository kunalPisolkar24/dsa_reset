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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    function<void(TreeNode *)> sol = [&](TreeNode *root) -> void {
      if (!root)
        return;
      sol(root->left);
      res.push_back(root->val);
      sol(root->right);
    };
    sol(root);
    return res;
  }
};
