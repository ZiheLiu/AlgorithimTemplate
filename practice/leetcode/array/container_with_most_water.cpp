#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * https://leetcode.com/problems/container-with-most-water/description/
 * 题意
 *  给定一个数组heights，对于下标为i和j的元素的面积为：abs(i - j) * min(heights[i], heights[j])
 *  求面积的最大值。
 */

/**
 * 对于当前下标为left和right的元素。
 * 考虑宽度比当前少1的情况，这个时候面积的高度要比当前高才可能比当前的面积大。
 * 所以要把heights[left]和heights[right]中小的位置向中心缩减1（left++或right--)。
 * 依次遍历下去即可。
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};
