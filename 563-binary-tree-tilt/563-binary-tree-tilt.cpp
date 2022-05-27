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
    int sum(TreeNode* root) {
        if (root==NULL) return 0;
        return sum(root->left)+sum(root->right)+root->val;
    }
    void func(TreeNode* root) {
        if (root==NULL) return;
        root->val=abs(sum(root->left)-sum(root->right));
        func(root->left);
        func(root->right);
    }
    int findTilt(TreeNode* root) {
        func(root);
        return sum(root);
    }
};