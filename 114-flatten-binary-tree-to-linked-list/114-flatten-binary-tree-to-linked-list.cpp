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
    TreeNode* flattenTree(TreeNode* root){
        if(root==NULL) return NULL;
        if(root->left == NULL && !root->right){
            return root;
        }
        TreeNode* t = root->right;
        root->right = flattenTree(root->left);
        TreeNode* tail = root;
        while(tail->right){
            tail = tail->right;
        }
        tail->right = flattenTree(t);
        root->left = NULL;
        return root;
    }
    
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};