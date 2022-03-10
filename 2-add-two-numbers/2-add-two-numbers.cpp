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
		ListNode *p1=l1,*p2=l2;
		ListNode *dummy=new ListNode(-1),*t=dummy;
		int carry=0;
		while(p1 || p2 || carry){
			if(p1) {
				carry+=p1->val;
				p1=p1->next;
			}
			if(p2) {
				carry+=p2->val;
				p2=p2->next;
			}
			ListNode *temp=new ListNode(carry%10);
			t->next=temp;
			t=temp;
			carry/=10;
		}
		return dummy->next;
	}
};