/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
*/
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        set<int> to_delete_set;//这里我想把to_delete换成set做查找 降低效率 感觉vector换成set好麻烦
        for(int i = 0; i < to_delete.size(); i++){
            to_delete_set.insert(to_delete[i]);
        }
        root = process(root, to_delete_set, res);
        if(root) res.push_back(root);
        return res;
    }
private:
    TreeNode* process(TreeNode* root, set<int>& to_delete_set, vector<TreeNode*>& res){//该函数为什么不能直接用public的变量？？
        if(!root) return nullptr;
         root->left, root->right = process(root->left, to_delete_set, res), process(root->right, to_delete_set, res);

        if(to_delete_set.find(root->val)!=to_delete_set.end()){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            return nullptr;
        }
        return root;

    }
};//出现runtime error 编译不通过
