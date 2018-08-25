#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * https://leetcode.com/problems/next-permutation/description/
 * 题意
 *  给定一个数组，把所有这些数字进行全排列、按照字典序递增顺序排序，求这个数组的下一个全排列。
 */

/**
 * 解法
 *  1 4 6 5 3 2
 *  1 5 2 3 4 6
 *
 *  从右向左遍历，找到第一个递减的数字i
 *      - 找到(i, n) 中比nums[i]大的最小的数字，把这两个数字调换。
 *      - 把(i, n) 中的数字，按照递减顺序。因为(i, n)中的数字是按照递增顺序，所以把(i, n)中的数字倒置即可。
 */

class Solution {
private:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int i, j;
        for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i + 1]; i--) {}

        if (i != -1) {
            auto iter = upper_bound(nums.rbegin(), nums.rend() - 1 - i, nums[i]);
            j = nums.size() - 1 - (iter - nums.rbegin());
            swap(nums, i, j);
        }

        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            swap(nums, left++, right--);
        }
    }
};

int main() {
    vector<int> nums = {1, 5, 4};
    Solution().nextPermutation(nums);
    for (int num : nums) {
        cout << num <<endl;
    }
}
