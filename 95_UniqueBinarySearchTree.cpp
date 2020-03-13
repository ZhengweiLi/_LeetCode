/*
Given an integer n, generate all structurally unique BST's
(binary search trees) that store values 1 ... n.
//左子树所有节点的值均小于根节点的值，右子树所有节点的值均大于根节点的值
Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        helper(1, n);
        return res;
    }
    vector<TreeNode*> helper(int begin, int end){
        if(begin > end) return {nullptr};
        vector<TreeNode*> res;

        for(int i = begin; i <= end; i++){
            auto left = helper(begin, i - 1), right = helper(i + 1, end);
            for(auto a : left){
                for(auto b : right){

                    TreeNode* node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
