/*
Given n points on a 2D plane,
find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++){

            int duplicate = 1;
            map<pair<int, int>, int> m;
            for(int j = i + 1; j < points.size(); j++){
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1]){
                    ++duplicate;
                    continue;
                }

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcd(dx, dy);
                ++m[{dx/d, dy/d}];
            }
            res = max(res, duplicate);
            for(auto it = m.begin(); it != m.end(); it++){
                res = max(res, it->second + duplicate);
            }
        }
        return res;
    }
    int gcd(int a, int b){
        return (b == 0)? a : gcd(b, a % b);
    }
};
