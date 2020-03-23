/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* t = st.top(); st.pop();
            res.insert(res.begin(), t->val);

            if(t->left) st.push(t->left);
            if(t->right) st.push(t->right);
        }
        return res;
    }
};
