#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * 求对于nums的最长递增（或不递减）子序列。
 * length_min_num[i]记录长度为i的递增子序列，末尾数字的最小值。
 * max_length记录遍历到nums[i]时能得到的最长递增子序列。
 * 遍历nums数组，维护max_length和length_min_num。
 *  - 如果nums[i] > length_min_num[max_length]，则可以把nums[i]接在最长的子序列后边，length_min_num[++max_length] = nums[i]。
 *  - 否则在当前的length_min_num中找第一个不必nums[i]小的数字（位置pos)，用nums[i]替换它。
 *      因为这样替换之后，长度为pos的最长公共子序列的末尾数字会变小，这样更有利于后续数字接在它后边。
 *
 * 注意最后length_min_num数组中记录的不是最长递增子序列的每个元素，只是每个长度的子序列的末尾元素。
 * 要获得每个元素，要再加一个数组，记录每个元素的前一个元素是什么。
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        // length_min_num[i]: 长度为i+1的最长公共子序列的末尾数字的最小值
        int length_min_num[nums.size()];

        length_min_num[0] = nums[0];
        int max_length = 0;

        for (int i = 1; i < nums.size(); i++) {
            // 如果是非递减子序列 if (nums[i] >= length_min_num[max_length]) {
            if (nums[i] > length_min_num[max_length]) {
                length_min_num[++max_length] = nums[i];
            } else {
                int pos = lower_bound(length_min_num, length_min_num + max_length, nums[i]) - length_min_num;
                length_min_num[pos] = nums[i];
            }
        }

        return max_length + 1;
    }
};

int main() {
    vector<int> nums = {2, 2};
    auto num = Solution().lengthOfLIS(nums);
    cout << num;
}
