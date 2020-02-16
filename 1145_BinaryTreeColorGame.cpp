/*
Two players play a turn based game on a binary tree.
  We are given the root of this binary tree, and the number of nodes n in the tree.
n is odd, and each node has a distinct value from 1 to n.

Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
Output: true
Explanation: The second player can choose the node with value 2.
*/
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        nodes(root, x);
        int p = n - (l_ + r_ + 1);
        return max(p, max(l_, r_)) > n/2;
    }
private:
    int l_;
    int r_;

    int nodes(TreeNode* root, int x){
        if(!root) return 0;
        int l = nodes(root->left, x);
        int r = nodes(root->right, x);

        if(root->val == x){
            l_ = l;
            r_ = r;
        }
        return r + l +1;
    }
};
