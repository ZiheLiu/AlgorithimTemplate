#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 问题
 * 给定一个整数数组，求连续子数组的乘积最大值。
 */

/**
 * HINT
 * 使用max[i]记录以i为结尾的乘积最大值，
 * 使用min[i]记录以i为结尾的乘积最小值，
 * 使用ans[i]记录到i位置的答案。
 *
 * 可以不用开数组，开三个变量，迭代即可。
 */

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int maxherepre = nums[0];
    int minherepre = nums[0];
    int ans = nums[0];
    int maxhere, minhere;

    for (int i = 1; i < nums.size(); i++) {
      maxhere = max(max(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
      minhere = min(min(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
      ans = max(maxhere, ans);
      maxherepre = maxhere;
      minherepre = minhere;
    }
    return ans;
  }
};


int main() {

  vector<int> nums = {5, -2};
  cout << Solution().maxProduct(nums);

  return 0;
}
