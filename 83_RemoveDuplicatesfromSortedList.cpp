/*
Given a sorted linked list,
delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
*/
/**
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
        ListNode* cur = head;
        while(cur && cur->next){

            if(cur->val == cur->next->val){
                cur->next = cur->next->next;
            }
            else cur = cur->next;
        }
        return head;
    }
};
