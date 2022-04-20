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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        return check(nums, k);
    }
    
    void inorder(TreeNode* root, vector<int> &nums){
        if(root==NULL)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
        
    }
    
    bool check(vector<int> vec, int target){
        int i=0;
        int j = vec.size()-1;
        while(i<j){
            if(vec[i]+vec[j] == target){
                return true;
            }
            
            if(vec[i]+vec[j]>target){
                j--;
            }
            
            else{
                i++;
            }
            
            
        }
        return false;
    }
};