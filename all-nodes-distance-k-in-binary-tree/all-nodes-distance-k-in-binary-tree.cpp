/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //mark parents
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &markP){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                markP[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                markP[curr->right] = curr;
                q.push(curr->right);
            }
            
        }
    }
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> markP;
        markParents(root, markP);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++==k) break;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]= true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(markP[curr] && !visited[markP[curr]]){
                    q.push(markP[curr]);
                    visited[markP[curr]] = true;
                }
            }
        
        
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            result.push_back(curr->val);
        }
        return result;
    }
};