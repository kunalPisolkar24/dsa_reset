#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int longestPathWithSum(TreeNode *root, int targetSum) {

    int mx = 0;
    unordered_map<long long, int> ump;
    ump[0] = 0;

    function<void(TreeNode *, int, int)> sol = [&](TreeNode *node, int sum,
                                                   int lev) -> void {
      if (!node)
        return;

      sum += node->val;

      if(ump.count(sum - targetSum)) {
        mx = max(mx, lev - ump[sum - targetSum]);
      }

      if(!ump.count(sum)) {
        ump[sum] = lev;
      }

      sol(node->left, sum, lev + 1);
      sol(node->right, sum, lev + 1);

      if(ump[sum] == lev) {
        ump.erase(sum);
      }
    };

    sol(root, 0, 1);
    return mx;
  }
};
