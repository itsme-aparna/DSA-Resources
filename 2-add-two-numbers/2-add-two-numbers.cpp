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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        
        int carry = 0;
        ListNode* prev = new ListNode(0);
        prev->next = l1;
        while(temp1 && temp2){
            int sum = temp1->val + temp2->val + carry;
            if(sum >9){
                carry = 1;
                sum = sum-10;
            }
            else{
                carry = 0;
            }
            
            temp1->val = sum;
            temp1 = temp1->next;
            prev = prev->next;
            temp2 = temp2->next;
        }
        
        
        
        while(temp1 != NULL){
            cout<<"addv";
            int sum = temp1->val + carry;
            if(sum >9){
                carry = 1;
                sum = sum-10;
            }
            else{
                carry = 0;
            }
            
            temp1->val = sum;
            prev = temp1;
            temp1= temp1->next;
        }
        
        while(temp2 != NULL){
            int sum = temp2->val + carry;
            if(sum >9){
                carry = 1;
                sum = sum-10;
            }
            else{
                carry = 0;
            }
            temp2->val = sum;
            prev->next = temp2;
            prev = prev->next;
            temp2 = temp2->next;
        }
        
        if(carry == 1){
            ListNode* node = new ListNode(1);
            prev->next = node;
        }
        return l1;
    }
};