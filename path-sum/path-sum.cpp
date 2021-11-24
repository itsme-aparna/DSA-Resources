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
    
    bool Tsum(TreeNode* root, int sum){
        if(root==NULL) return false;
        if(root->right==NULL && root->left==NULL){return sum-(root->val)==0;}
        
        return Tsum(root->left, sum-(root->val)) || Tsum(root->right, sum-(root->val));
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return Tsum(root, targetSum);
    }
};