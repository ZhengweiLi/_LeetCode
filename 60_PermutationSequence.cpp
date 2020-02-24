/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);

        for(int i = 1; i < n; i++)
            f[i] = f[i-1]*i;
        k--;

        for(int i = n; i >= 1; i--){
            int j = k / f[i-1];
             k = k % f[i-1];// int k = k % f[j-1] 为何会出现不一样的答案

            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};
