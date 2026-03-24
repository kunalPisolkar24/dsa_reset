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
  int countNodesGE(TreeNode *root, int x) {
    int count = 0;
    function<void(TreeNode *)> sol = [&](TreeNode *root) -> void {
      if (!root)
        return;
      if(root->val >= x) count++;
      sol(root->left);
      sol(root->right);
    };
    sol(root);
    return count;
  }
};
