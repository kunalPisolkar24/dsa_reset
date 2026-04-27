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
    vector<int> best, temp;

    function<void(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> void {
      if (!node)
        return;

      temp.push_back(node->val);
      sum += node->val;

      if (!node->left and !node->right) {
        if (sum > mx) {
          mx = sum;
          best = temp;
        }
        temp.pop_back();
        return;
      } else {
        sol(node->left, sum);
        sol(node->right, sum);
      }
      temp.pop_back();
    };

    sol(root, 0);
    return best;
  }
};
