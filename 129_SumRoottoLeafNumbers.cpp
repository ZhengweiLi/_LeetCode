/*
Given a binary tree containing digits from 0-9 only,
 each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
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
    int sumNumbers(TreeNode* root) {
        return sumNumbersDFS(root, 0);
    }
    int sumNumbersDFS(TreeNode* root, int sum){
        if(!root) return 0;
        sum = sum * 10 + root->val;
        if(!root->left && !root->right) return sum;

        return sumNumbersDFS(root->left, sum) +sumNumbersDFS(root->right, sum);
    }
};
