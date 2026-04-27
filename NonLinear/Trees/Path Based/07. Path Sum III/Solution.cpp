#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int pathSum(TreeNode *root, int targetSum) {
    unordered_map<long long, int> ump;
    ump[0] = 1;
    function<int(TreeNode *, int)> sol = [&](TreeNode *node, int sum) -> int {
      if (!node)
        return 0;
      int count = 0;
      sum += node->val;
      if (ump.count(sum - targetSum)) {
        count += ump[sum - targetSum];
      }
      ump[sum]++;
      count += sol(node->left, sum);
      count += sol(node->right, sum);
      ump[sum]--;
      return count;
    };
    return sol(root, 0);
  }
};
