/*
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.
Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n=lists.size();

        while(n>1){
            int k=(n+1)/2;
            for(int i=0;i<n/2;i++){
                lists[i]=mergeTwoLists(lists[i],lists[i+k]);
            }
            n=k;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(-1),*res=dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
            res->next=l1;
            l1=l1->next;
            }
            else{
            res->next=l2;
            l2=l2->next;
            }
           res=res->next;
        }
        res->next=l1?l1:l2;
        return dummy->next;
    }
};
