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
    
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int h1 = height(root->left)+1;
        int h2 = height(root->right)+1;
        return max(h1, h2);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(abs((height(root->right)-height(root->left)))>1){
            return false;
        }
        if(isBalanced(root->right) && isBalanced(root->left)){
            return true;
        }
        
        return false;
    }
};