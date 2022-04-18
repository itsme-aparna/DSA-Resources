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
    void revinorder(TreeNode* root, int &ans){
        if(root==NULL)
            return;
        revinorder(root->right, ans);
        root->val += ans;
        ans = root->val;
        revinorder(root->left, ans);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        //go to the extereme right first, then start traversing backwards. 
        //
        int ans = 0; 
        revinorder(root, ans);
        return root;
    }
};