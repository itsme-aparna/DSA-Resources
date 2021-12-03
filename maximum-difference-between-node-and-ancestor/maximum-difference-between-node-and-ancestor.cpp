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
    
    void helper(TreeNode* root, int mini, int maxi, int &diff){
        if(!root)
            return;
        
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        
        diff = max(diff, abs(maxi-mini));
        
        helper(root->left, mini, maxi, diff);
        helper(root->right, mini, maxi, diff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        int diff = INT_MIN;
        helper(root, INT_MAX, INT_MIN, diff);
        return diff;
    }
};