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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int l, int r, int& curr){
        if(l>r){
            return NULL;
        }
        int i = 0;
        while(postorder[curr] != inorder[i]){
            i++;
        }
        curr--;
        
        TreeNode *node = new TreeNode(inorder[i]);
        
        node->right = solve(inorder, postorder, i+1, r, curr);
        node->left = solve(inorder, postorder, l, i-1, curr);
        
        return node;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size()-1;
        return solve(inorder, postorder, 0, n, n);
    }
};