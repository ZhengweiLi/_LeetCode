/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
*/
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        function<void(TreeNode*, stack<TreeNode*>&)> smallest = [&](TreeNode* root, stack<TreeNode*>& s){
            if(!root) return ;
            s.push(root);
            smallest(root->left, s);
        };

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        smallest(root1, s1);
        smallest(root2, s2);
        vector<int>res;

        while(!s1.empty() || !s2.empty()){
            stack<TreeNode*>& s = s1.empty()? s2 : s2.empty()? s1 : s1.top()->val < s2.top()->val? s1 : s2;
            TreeNode* n = s.top(); s.pop();
            res.push_back(n->val);
            smallest(n->right, s);
        }
        return res;

    }
};
