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
