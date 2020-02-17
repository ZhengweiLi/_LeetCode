/*
Given a binary tree, find the length of the longest path where each node in the path has the same value.
This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.
Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2
*/
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        univaluePath(root, res);
        return res;
    }
private:
    int univaluePath(TreeNode* root, int& res){
        if(!root) return 0;

        int l = univaluePath(root->left, res);
        int r = univaluePath(root->right, res);
        int pl = 0;
        int pr = 0;

        if(root->left && root->val == root->left->val) pl = l + 1;
        if(root->right && root->val == root->right->val) pr = r + 1;
        res = max(res, pl + pr);
        return max(pl, pr);
    }
};
