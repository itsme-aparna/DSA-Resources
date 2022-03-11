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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0)
            return head;
        if(head == NULL)
            return NULL;
        ListNode* fp = head;
        ListNode* sp = head;
        int len = 0;
        ListNode* x = head;
        while(x!=NULL){
            len++;
            x = x->next;
        }
        if(len<= k){
            k = k%len;
        }
        
        if(k==0 || len == 1)
            return head;
        while( sp->next && k--){
            sp = sp->next;
        }
        while(sp->next && sp->next!=NULL){
            fp = fp->next;
            sp = sp->next;
        }
        ListNode* temp = fp->next;
        fp ->next = NULL;
        sp->next = head;
        return temp;
    }
};