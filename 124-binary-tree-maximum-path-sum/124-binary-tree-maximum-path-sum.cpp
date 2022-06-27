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
    int func(TreeNode* root, int &maxi){
        if(root==NULL)
            return 0;
        
        int l = max(0, func(root->left, maxi));
        int r = max(0, func(root->right, maxi));
        int val = root->val;
        maxi = max(maxi, (l + r) + val);
        return max(l, r) + val;
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        func(root, maxi);
        return maxi;
    }
};