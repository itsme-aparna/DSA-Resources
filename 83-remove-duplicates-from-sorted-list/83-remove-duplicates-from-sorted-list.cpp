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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* curr1 = head;
        ListNode* curr2 = head;
        while(curr2 != NULL ){
            while(curr2 !=NULL && curr2->next !=NULL && curr2->val == curr2->next->val){
                curr2 = curr2->next;
            }
            
            curr1->next = curr2->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
            
        }
        
        return head;
    }
};