/*
Given an unsorted array, find the maximum difference
between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int n = nums.size(),res = 0, pre = 0;
        int mn = INT_MAX, mx = INT_MIN;

        for(int num : nums){
            mn = min(num, mn);
            mx = max(num, mx);
        }

        int size = (mx - mn) / n + 1;
        int cnt = (mx - mn) / size + 1;
        vector<int> bucket_min(cnt, INT_MAX);
        vector<int> bucket_max(cnt, INT_MIN);

        for(int num : nums){
            int idx = (num - mn) / size;
            bucket_min[idx] = min(num, bucket_min[idx]);
            bucket_max[idx] = max(num, bucket_max[idx]);
        }
        for(int i = 1; i < cnt; i++){
            if(bucket_min[i] == INT_MAX ||bucket_max[i] == INT_MIN) continue;
            res = max(res, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return res;

    }
};
