/*
Given a sorted linked list, delete all nodes that have duplicate numbers,
 leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/
**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;

        while(pre->next){
            ListNode* cur = pre->next;
            while(cur->next && cur->val == cur->next->val) cur = cur->next;

            if(pre->next != cur) pre->next = cur->next;
            else pre = pre->next;
        }
        return dummy->next;
    }
};
