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
    void dfs(TreeNode* root, int& num, int max_till_now){
        if(root==NULL)
            return;
        if(root->val>= max_till_now){
            num++;
            max_till_now = root->val;
        }
        
        dfs(root->left, num, max_till_now);
        dfs(root->right, num, max_till_now);
        
    }
    
    int goodNodes(TreeNode* root) {
        // dfs
        int num = 0;
        int max_till_now = INT_MIN;
        dfs(root, num, max_till_now);
        return num;
    }
};