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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            
            sum = 0;
            for(int i=0; i<sz; i++){
                TreeNode* x = q.front();
                q.pop();
                
                sum += x->val;
                
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        
        return sum;
    }
};