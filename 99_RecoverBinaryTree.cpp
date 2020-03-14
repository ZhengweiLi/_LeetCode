/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:
Input: [1,3,null,null,2]
   1
  /
 3
  \
   2

Output: [3,1,null,null,2]
   3
  /
 1
  \
   2
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //solution 1: recursion method, space complexity: O(n)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> val;
        inorder(root, list, val);

        sort(val.begin(), val.end());
        for(int i = 0; i < val.size(); i++){
            list[i]->val = val[i];
        }

    }
    void inorder(TreeNode* root, vector<TreeNode*>& list, vector<int>& val){
        if(!root) return;

        inorder(root->left, list, val);

        list.push_back(root);
        val.push_back(root->val);

        inorder(root->right, list, val);
    }
};
// solution 2: two pointers + recursion, space complexity: O(n)
class Solution {
public:
    TreeNode* pre = NULL, *first = NULL, *second = NULL;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);

        if(!pre) pre = root;
        else{
            if(pre->val > root->val){
                if(!first) first = pre;
                second = root;
            }
            pre = root;
        }
        inorder(root->right);
    }
};
//solution 3: stack method, space complexity : O(n)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL, *first = NULL, *second = NULL, *p = root;
        stack<TreeNode*> st;

        while(p || !st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            p = st.top(); st.pop();
            if(pre){
                if(pre->val > p->val){
                    if(!first) first = pre;
                    second = p;
                }
            }
            pre = p;
            p = p->right;
        }
        swap(first->val, second->val);
    }
};
