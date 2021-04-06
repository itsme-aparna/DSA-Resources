#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    struct Node* left;
    struct Node* right;

};

struct Node* newNode(char data){
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}

struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd, unordered_map<char, int>& mp){
    static int preIndex = 0;

    if(inStrt>inEnd)
         return NULL;
    
    char curr = pre[preIndex++];

    
}