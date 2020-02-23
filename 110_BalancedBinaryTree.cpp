/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height(root, &balanced);
        return balanced;
    }
    int height(TreeNode* root, bool* balanced){
        if(!root) return true;
        int left_height = height(root->left, balanced);
        int right_height = height(root->right, balanced);

        if(abs(left_height - right_height) > 1){
            *balanced = false;
            return -1;
        }
        return max(left_height, right_height) + 1;
    }
};
