#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * https://leetcode.com/problems/3sum/description/
 * 题意
 *  给一个数组nums，求所有不同的三元组，三元组的三个数和为0.
 */

/**
 * 解法
 *  数组从大到小排序.
 *  遍历数组，在遍历时，假设当前下标为i.
 *  使用两个指针，left = i + 1, right = nums.size() - 1.
 *  计算value = nums[i] + nums[left] + nums[right].
 *  如果value为0，则为解。
 *      并且向右跳过所有和nums[left]相同的值，向左跳过所有和nums[right]相同的值.
 *  如果value < 0，说明要增大值，所以left++.
 *  如果value > 0，说明要减小至，所以right--.
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            int num1 = nums[i];
            if (num1 > 0) {
                break;
            }
            if (i > 0 && num1 == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                int num2 = nums[j];
                int num3 = nums[k];
                int value = num1 + num2 + num3;
                if (value == 0) {
                    // printf("%d %d %d\n", num1, num2, num3);
                    ans.push_back(vector<int>{num1, num2, num3});
                    while (nums[++j] == num2) {}
                    while (nums[--k] == num3) {}
                } else if (value > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution().threeSum(nums);
}
