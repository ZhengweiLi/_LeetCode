/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes,
only nodes itself may be changed.
Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(-1),*pre=dummy;
        dummy->next=head;
        while(pre->next&&pre->next->next){

            ListNode* t=pre->next->next;
            pre->next->next=t->next;
            t->next=pre->next;
            pre->next=t;
            pre=t->next;
        }
        return dummy->next;
    }
};
