/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node.
 If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* p = root->next;
        while(p){

            if(p->left){
                p = p->left;
                break;
            }
            if(p->right){
                p = p->right;
                break;
            }
            p = p->next;
        }
        if(root->right) root->right->next = p;
        if(root->left) root->left->next = root->right? root->right : p;

        connect(root->right);
        connect(root->left);
        return root;
    }
};
