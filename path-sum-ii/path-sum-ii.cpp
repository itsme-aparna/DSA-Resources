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
    
    void pSum(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> ds){
        if(root==NULL) return;
        if(root->left== NULL && root->right ==NULL){
            if(targetSum-root->val == 0){
                ds.push_back(root->val);
                ans.push_back(ds);
                
            }
            
            return;
        } 
        ds.push_back(root->val);
        pSum(root->right, targetSum-root->val, ans, ds);
        pSum(root->left, targetSum- root->val, ans, ds);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        pSum(root, targetSum, ans, ds);
        return ans;
    }
};