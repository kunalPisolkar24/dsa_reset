#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    function<void(TreeNode *, string)> sol = [&](TreeNode *node,
                                                 string temp) -> void {
      if (!node)
        return;

      if (!node->left and !node->right) {
        ans.push_back(temp + to_string(node->val));
        return;
      }

      sol(node->left, temp + to_string(node->val) + "->");
      sol(node->right, temp + to_string(node->val) + "->");
    };

    sol(root, "");
    return ans;
  }
};
