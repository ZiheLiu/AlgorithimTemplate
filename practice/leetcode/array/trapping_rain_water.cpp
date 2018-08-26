#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

/**
 * https://leetcode.com/problems/trapping-rain-water/description/
 * 题意
 *  一个数组heights，heights[i]代表在第i个位置木板的高度。
 *  求这些木板最多能装的水的量。
 */

/**
 * 解法
 *  对于一段区间heights[left] > heights[left+1] > ... > heights[right-1] && heights[left] <= heights[right]。
 *  即当前位置i的下一个比它高的位置j之间的水量为sum(heights[left] - heights[i])(left < i < right)。
 *
 *  从左向右遍历数组，记录当前最高的位置cur_max_left，
 *      - 如果cur_max_left > heights[left]，则ans += heights[left] - cur_max_left
 *      - 如果cur_max_left > heights[left]，说明上一段的水完毕，进行下一段。cur_max_left = heights[left]。
 *
 *  但是，这样可能会存在有些区间，heights[right] <= heights[left]，即是反过来的情况。
 *  并且，可能没有right位置，即找不到比当前left位置高的位置了，这个时候要从方向进行遍历。
 *  所以要从右向左再遍历一边数组，重复刚刚的过程。
 *
 *  可以把两个方向的遍历结合在一起。
 *  用left指针和right指针从两个方向遍历。每次处理两个木板中低的地方，因为这样可以尽可能避免找不到比端点高的位置的情况。
 *      - 如果heights[left] < heights[right]，从left位置进行计算。
 *      - 否则，从right位置进行计算。
 */

class Solution {
public:
    int trap(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int ans = 0;
        int cur_max_left = 0;
        int cur_max_right = 0;
        while (left <= right) {
            if (heights[left] < heights[right]) {
                if (cur_max_left < heights[left]) {
                    cur_max_left = heights[left];
                } else {
                    ans += cur_max_left - heights[left];
                }
                left++;
            } else {
                if (cur_max_right < heights[right]) {
                    cur_max_right = heights[right];
                } else {
                    ans += cur_max_right - heights[right];
                }
                right--;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    auto num = Solution().trap(nums);
    cout << num;
}
