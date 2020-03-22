/*
A linked list is given such that each node contains an additional random pointer
 which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes.
Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1)
where random pointer points to, or null if it does not point to any node.


Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* res = new Node(head->val);
        Node* cur = head->next;
        Node* node = res;

        unordered_map<Node*, Node*> m;
        m[head] = res;

        while(cur){
            Node* t = new Node(cur->val);
            node->next = t;
            m[cur] = t;
            cur = cur->next;
            node = node->next;
        }
        cur = head, node = res;
        while(cur){
            node->random = m[cur->random];
            cur = cur->next;
            node = node->next;
        }
        return res;
    }
};
