#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 * 题意
 *  给两个排好序（递增）的数组，求这两个数组的所有数中的中位数。
 *  这两个数组至少有一个为非空数组。
 */

/**
 * 解法
 *  对于数组nums、nums2，长度为size1、size2
 *  我们要找到中位数位置，nums[i - 1]、nums[i]、nums2[j - 1]、nums2[j]。
 *  nums[i - 1]     nums[i]
 *  nums2[j - 1]    nums2[j]
 *  要保证两个条件：
 *      - size(nums[0], ..., nums[i - 1]) + size(nums2[1], ..., nums2[j - 1]) = size(nums[i], ..., nums[size1]) + size(nums2[j], ..., nums2[size2])
 *      - max(nums[i - 1], nums2[j - 1]) <= min(nums[i], nums2[j])
 *  这样可以保证max(nums[i - 1], nums2[j - 1])这个数之前有i + j - 1个数字。
 *  而第一个中位数前边有mid = (size1 + size2 - 1) / 2个数字。
 *  即mid = (size1 + size2 - 1) / 2 = i + j - 1。
 *
 *  二分：
 *      设left = 0, right = size1 - 1。
 *      最后left是i, right是i - 1。
 *      取m1 = (left + right)/2，则m2 = mid - m1。
 *      m1最后为i - 1，m2最后为j。
 *      所以我们要找到nums[m1] < nums[m2]中的m1的最大的位置。
 *      所以如果nums[m1] < nums[m2]，则left = m1 + 1，否则right = m1 - 1。
 *
 *  最后的答案：
 *      如果size1 + size2为奇数，则中位数为max(nums[i - 1], nums2[j - 1])
 *      如果size1 + size2为偶数，则中位数为(max(nums[i - 1], nums2[j - 1]) + min(nums[i], nums2[j])) / 2。
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size()) {
            swap(nums1, nums2);
        }
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;

        // 比第一个中位数小的数的个数
        // mid = (size1 + size2 - 1) / 2 = i + j - 1
        int mid = (size - 1) / 2;
        int left = 0;
        int right = size1 - 1;
        // 最后left是i, right是i - 1
        while (left <= right) {
            // 最后是i - 1
            int mid1 = (right + left) / 2;
            // 最后是j
            int mid2 = mid - mid1;
            if (mid2 >= size2 || (mid2 >= 0 && nums1[mid1] < nums2[mid2])) {
                left = mid1 + 1;
            } else {
                right = mid1 - 1;
            }
        }
        int i = left;
        int j = mid - right;

        int num1;
        if (i - 1 >= 0 && j - 1 >= 0) {
            num1 = max(nums1[i - 1], nums2[j - 1]);
        } else if (i - 1 >= 0) {
            num1 = nums1[i - 1];
        } else {
            num1 = nums2[j - 1];
        }

        if (size & 1) {
            return num1;
        }

        int num2;
        if (i < size1 && j < size2) {
            num2 = min(nums1[i], nums2[j]);
        } else if (i < size1) {
            num2 = nums1[i];
        } else {
            num2 = nums2[j];
        }
        return double(num1 + num2) / 2;
    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {1, 1};
    cout << Solution().findMedianSortedArrays(nums1, nums2);
}
