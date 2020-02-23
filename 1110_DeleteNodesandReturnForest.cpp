/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
*/

// unordered_set : Hash set O(1), pointer: scattered memory
// set: Red-black tree (Balanced binary tree): O(LogN), pointer: scattered memory
// vector: O(N): continuous memeory,
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        set<int> to_delete_set(to_delete.begin(), to_delete.end());

        root = process(root, to_delete_set, res);
        if(root) res.push_back(root);
        return res;
    }
private:
    TreeNode* process(TreeNode* root, set<int>& to_delete_set, vector<TreeNode*>& res){
        if(!root) return nullptr;
         root->left = process(root->left, to_delete_set, res);
         root->right = process(root->right, to_delete_set, res);

        if(to_delete_set.find(root->val)!=to_delete_set.end()){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            return nullptr;
        }
        return root;

    }
};
