#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> maxPath(TreeNode *root) {
    int mx = INT_MIN;
    vector<int> best;
    vector<int> temp;

    function<void(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> void {
      if (!node)
        return;

      temp.push_back(node->val);

      if (!node->left and !node->right) {
        if (sum > mx) {
          mx = sum;
          best = temp;
        }
        temp.pop_back();
        return;
      } else {
        sol(node->left, sum + (node->left ? node->left->val : 0));
        sol(node->right, sum + (node->right ? node->right->val : 0));
      }
      temp.pop_back();
    };

    sol(root, root->val);
    return best;
  }
};
