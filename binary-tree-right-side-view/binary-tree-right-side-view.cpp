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
    
    void util(TreeNode* root, vector<int> &ans, int level, int &maxlevel){
        if(root==NULL)
            return;
        if(level>maxlevel){
            maxlevel = level;
            ans.push_back(root->val);
        }
        util(root->right, ans, level+1, maxlevel);
        util(root->left, ans, level+1, maxlevel);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return{};
        vector<int> ans;
        int maxlevel = INT_MIN;
        util(root, ans, 0, maxlevel);
        return ans;
    }
};