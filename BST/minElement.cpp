#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* Insert(Node* node, int value){
     if(node == NULL){
         return newNode(value);
     }
     else{
         if(node->data>value){
             node->left = Insert(node->left, value);
         }
         else{
             node->right = Insert(node->right, value);
         }
         return node;
     }


}

int minValue(Node* root){
      if(root->left == NULL) return root->data;
      minValue(root->left);
}

int main(){
    int t;
    struct Node* root = newNode(1);
    cin>>t;
    while(t--){
        Insert(root, t);

    }
    cout<<minValue(root);
    getchar();
    return 0;
}