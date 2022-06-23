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
    void pathToLeaf(vector<vector<int>>& ans, vector<int> &ds, TreeNode* root, int sum){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right==NULL){
            if(sum - root->val == 0){
                ds.push_back(root->val);
                ans.push_back(ds);
                ds.pop_back();
            }
            return;
        }
        ds.push_back(root->val);
        pathToLeaf(ans, ds, root->left, sum-root->val);
        pathToLeaf(ans, ds, root->right, sum-root->val);
        ds.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        pathToLeaf(ans, ds, root, targetSum);
        return ans;
    }
};