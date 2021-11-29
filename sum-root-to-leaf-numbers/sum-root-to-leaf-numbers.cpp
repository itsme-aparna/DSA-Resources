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
    
    int sumOfNodes(TreeNode* root, int curr){
        if(root==NULL)
            return 0;
        else{
            curr = root->val+ curr*10;
            if(!root->right && !root->left){
                return curr;
            }
            return sumOfNodes(root->right, curr)+sumOfNodes(root->left, curr);
            
        }
    }
    
    int sumNumbers(TreeNode* root) {
        
        return sumOfNodes(root, 0);
    }
};