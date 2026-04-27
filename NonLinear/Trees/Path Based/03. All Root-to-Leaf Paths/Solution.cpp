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
    vector<int> temp;
    function<void(TreeNode *)> sol = [&](TreeNode *node) -> void {
      if (!node)
        return;

      temp.push_back(node->val);

      if (!node->left and !node->right) {
        string tmp = "";
        for (int i = 0; i < temp.size(); i++) {
          tmp += to_string(temp[i]);
          if (i != temp.size() - 1) {
            tmp += "->";
          }
        }
        ans.push_back(tmp);
        temp.pop_back();
        return;
      }

      sol(node->left);

      sol(node->right);
      temp.pop_back();
    };

    sol(root);
    return ans;
  }
};
