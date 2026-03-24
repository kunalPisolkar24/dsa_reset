#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool sol(TreeNode *p, TreeNode *q) {
        if(!p and !q) return true;
        if((p and !q) or (!p and q)) return false;
        if(p->val != q->val) return false;
        return sol(p->left, q->right) and sol(p->right, q->left);
    }
    bool isMirror(TreeNode* root) {
        if(!root) return true;
        return sol(root->left, root->right);
    }
};
