#include <bits/stdc++.h>
using namespace std;
  
// Structure of a tree node.
struct Node {
    int key;
    Node *left, *right;
};
  
// Function to create new tree node.
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

int largestSubtree(Node* root, int& ans){
    if(root==NULL){
        return 0;
    }

    int currSum = root->key +largestSubtree(root->left, ans)+ largestSubtree(root->right, ans);
    ans = max(ans, currSum);


    return currSum;
}

int largestUtil(Node* root){
    if(root==NULL)
        return 0;
    int ans  = INT_MIN;

    largestSubtree(root, ans);

    return ans;
}

int main()
{
    
  
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
  
    cout << largestUtil(root);
    return 0;
}