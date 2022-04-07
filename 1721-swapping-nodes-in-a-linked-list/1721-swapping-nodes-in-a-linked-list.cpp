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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* te = new ListNode(0);
        te->next = head;
        while(k--){
            te = te->next;
            temp = temp->next;
        }
        
        ListNode* n1 = head;
        ListNode* n2 = temp;
        while(n2!= NULL){
            n1 = n1->next;
            n2 = n2->next;
        }
        
        int t = te->val;
        te->val = n1->val;
        n1->val = t;
        
        return head;
    }
};