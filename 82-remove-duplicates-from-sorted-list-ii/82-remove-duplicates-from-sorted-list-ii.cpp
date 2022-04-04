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
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *prev = dummyHead, *curr = head;
        while(curr){
            bool dup = false;
            while(curr->next && curr->val== curr->next->val){
                dup = true;
                curr = curr->next;
            }
            
            if(dup){
                prev->next = curr->next;
                
            }
            else{
                prev = curr;
                
            }
            
            curr = curr->next;
        }
        
        return dummyHead->next;
    }
};