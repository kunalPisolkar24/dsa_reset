#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int countPathsWithSumK(TreeNode *root, int k) {
    unordered_map<long long, int> ump;
    ump[0] = 1;

    long long ans = 0;

    function<void(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> void {
      if (!node)
        return;
      sum += node->val;
      if (ump.count(sum - k)) {
        ans += ump[sum - k];
      }

      ump[sum]++;
      sol(node->left, sum);
      sol(node->right, sum);
      ump[sum]--;
    };
    sol(root, 0);
    return (int)ans;
  }
};
