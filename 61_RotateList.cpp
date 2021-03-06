/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int n = 0;
        ListNode* cur = head;

        while(cur){
            ++n;
            cur = cur->next;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        k %= n;

        for(int i = 0; i < k; i++){
            fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = head;
        fast = slow->next;
        slow->next = NULL;

        return fast;
    }
};
