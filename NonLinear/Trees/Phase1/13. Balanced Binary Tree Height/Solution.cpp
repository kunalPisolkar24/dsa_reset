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
  int checkHeight(TreeNode *root) {
    if (!root)
      return 0;
    int left = checkHeight(root->left);
    int right = checkHeight(root->right);
    if (left == -1 or right == -1)
      return -1;
    if (abs(left - right) > 1) {
      return -1;
    }
    return 1 + max(left, right);
  }
};
