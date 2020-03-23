/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return{};
        stack<TreeNode*> st;
        st.push(root);
        vector<int> res;

        while(!st.empty()){
            TreeNode* t = st.top(); st.pop();
            res.push_back(t->val);

            if(t->right) st.push(t->right);
            if(t->left) st.push(t->left);
        }
        return res;
    }
};
