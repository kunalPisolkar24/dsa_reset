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
    function<void(TreeNode *, string &)> sol = [&](TreeNode *node,
                                                   string &temp) -> void {
      if (!node)
        return;

      int len = temp.size();
      temp += to_string(node->val);
      if (!node->left and !node->right) {
        ans.push_back(temp);
      } else {
        temp += "->";
        sol(node->left, temp);
        sol(node->right, temp);
      }
      temp.resize(len);
    };

    string t;
    sol(root, t);
    return ans;
  }
};
