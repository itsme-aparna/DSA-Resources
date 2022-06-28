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
    int widthOfBinaryTree(TreeNode* root) {
        if(root== NULL)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            int mini = q.front().second;
            int start, end;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front().first;
                int idx = q.front().second- mini;
                q.pop();
                
                if(i == 0){
                    start = idx;
                }
                if(i==n-1){
                    end = idx;
                }
                if(node->left){
                    q.push({node->left, (long)idx*2+1});
                }
                if(node->right){
                    q.push({node->right, (long)2*idx+2});
                }
            }
            ans = max(ans, end-start+1);
        }
        
        return ans;
    }
};