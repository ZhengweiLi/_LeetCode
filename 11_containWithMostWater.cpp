/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and nis at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0,i=0,j=height.size()-1;
        while(i<j){
            res=max(res,min(height[i],height[j])*(j-i));
            (height[i]<height[j])?i++:j--;

        }
        return res;

    }
};
