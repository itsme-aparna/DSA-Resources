#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

void zigzagTraversal(struct Node* root){
    if(!root)
        return;
    stack<struct Node*> currLevel;
    stack <struct Node*> nextLevel;

    currLevel.push(root);

    bool leftToRight = true;
    while(!currLevel.empty()){
        struct Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout<<temp->data<<" ";

            if(leftToRight){
                if(temp->left)
                     nextLevel.push(temp->left);
                if(temp->right)
                    nextLevel.push(temp->right);

            }

            else{
                if(temp->right)
                      nextLevel.push(temp->right);
                if(temp->left)
                       nextLevel.push(temp->left);
            }
        }

        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }

}

struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

// driver program to test the above function
int main()
{
    // create tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";

    zigzagTraversal(root);

    return 0;
}