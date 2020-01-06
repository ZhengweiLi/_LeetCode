/*Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur=new ListNode(-1),* dummy=cur;
        int carry=0;
        int sum=0;
        while(l1||l2){
            int val1=l1?l1->val:0;
            int val2=l2?l2->val:0;
            sum=val1+val2+carry;
            carry=sum/10;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;

        }
        if(carry) cur->next=new ListNode(1);
        return dummy->next;
    }
};
