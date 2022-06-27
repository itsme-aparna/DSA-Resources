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
    void flatten(TreeNode* root) {
        TreeNode* prev = root;
        TreeNode* curr = root;
        while(curr!= NULL){
            if(curr->left){
                prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                    
                }
                
                prev->right = curr->right;
                if(curr->left)
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

// while (root) {
// 		if (root->left && root->right) {
// 			TreeNode* t = root->left;
// 			while (t->right)
// 				t = t->right;
// 			t->right = root->right;
// 		}

//         if(root->left)
// 		    root->right = root->left;
// 		root->left = NULL;
// 		root = root->right;
// 	}