/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes
from some starting node to any node in the tree along the parent-child connections.
The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
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
    int maxPathSum(TreeNode* root) {

        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int& res){
        if(!root) return 0;
        int left = max(helper(root->left, res), 0);
        int right = max(helper(root->right, res), 0);

        res = max(res, left + right + root->val);
        return max(left, right) + root->val;
    }
};
