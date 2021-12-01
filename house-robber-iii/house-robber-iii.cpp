/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int func(TreeNode* root, int& lm, int& rm){
        if(!root) return 0;
        int lm1 = 0, lm2 = 0, rm1 = 0, rm2 = 0;
        lm = func(root->left, lm1, rm1);
        rm = func(root->right, lm2, rm2);
    
        return max(root->val + lm1 + rm1 + lm2 + rm2, lm + rm);
  }
    
    
    int rob(TreeNode* root) {
        int lm=0;
        int rm = 0;
        return func(root, lm, rm);
    }
};