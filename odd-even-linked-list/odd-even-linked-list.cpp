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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ans = head;
        if(!head) return head;
        ListNode* even = head->next;
        ListNode* evenhead = even;
        
        while(head!=NULL && head->next && head->next->next){
            head->next = head->next->next;
            even->next = even->next->next;
            head = head->next;
            even = even->next;
        }
        head->next = evenhead;
        return ans;
    }
};

