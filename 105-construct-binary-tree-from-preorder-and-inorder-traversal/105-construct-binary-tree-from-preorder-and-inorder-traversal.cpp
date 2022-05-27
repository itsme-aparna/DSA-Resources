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
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int l, int r, int &curr){
        if(l>r)
            return NULL;
        int i=0;
        while(preorder[curr] != inorder[i]){
            i++;
        }
        curr++;
        TreeNode* node = new TreeNode(inorder[i]);
        node->left = solve(preorder, inorder, l, i-1, curr);
        node->right = solve(preorder, inorder, i+1, r, curr);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size()-1;
        int curr = 0;
        return solve(preorder, inorder, 0, n, curr);
    }
};