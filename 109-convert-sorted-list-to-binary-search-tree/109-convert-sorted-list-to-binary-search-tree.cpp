/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* constructBST(vector<int>& arr,int start, int end){
        if(start>end){
            return NULL;
            
        }
        int mid = (start+end)/2;
        int midData = arr[mid];
        TreeNode* root = new TreeNode(midData);
        root->left = constructBST(arr, start, mid-1);
        root->right = constructBST(arr, mid+1, end);
        return root;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        
        return constructBST(arr, 0, arr.size()-1);
    }
};