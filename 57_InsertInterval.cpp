/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), cur = 0;
        vector<vector<int>> res;

        while(cur < n && intervals[cur][1] < newInterval[0]){
            res.push_back(intervals[cur++]);
        }
        while(cur < n && intervals[cur][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[cur][0]);
            newInterval[1] = max(newInterval[1], intervals[cur][1]);
            cur++;
        }
        res.push_back(newInterval);

        while(cur < n){
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};
