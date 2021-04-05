#include <bits/stdc++.h>
using namespace std;

void diagonalPrint(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;

    q.push(root);

    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            if(q.empty())
               return;
            cout << endl;

            q.push(NULL);


        }

        else{
            while(temp){
                cout<< temp->data<<" ";

                if(temp->left)
                    q.push(temp->left);

                temp = temp->right;
            }
        }
    }
        
}