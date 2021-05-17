#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void removeDuplicates(Node* head){
    Node* free_;
    if(head == NULL){
        return;
    }

    if(head->next!=NULL){
        if(head->data == head->next->data){
            free_ = head->next;
            head->next = head->next->next;
            free(free_);
            removeDuplicates(head);
        }

        else{
            removeDuplicates(head->next);
        }
    }
}

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();

    new_node->data = new_data;
    
}