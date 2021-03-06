/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same
if they are structurally identical and the nodes have the same value.

Example 1:
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((p && !q) || (!p && q) || (p->val != q->val)) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
