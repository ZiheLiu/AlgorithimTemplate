#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/**
 * 问题:
 * 给定一个二维数组，每一行数字递增，每一行第一个数字大于上一行最后一个数字。问一个数字是否存在于这个二维数字中。
 * [
 *  [1,   3,  5,  7],
 *  [10, 11, 16, 20],
 *  [23, 30, 34, 50]
 * ]
 */

/**
 * Hint:
 * 先区间上二分，找到可能存在数字的行。
 * 再在这一行进行二分。
 */

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    if (n <= 0) {
      return false;
    }
    int m = matrix[0].size();
    if (m <= 0) {
      return false;
    }

    int left = 0, right = n - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      int mid_min = matrix[mid][0];
      int mid_max = matrix[mid][m - 1];

      if (mid_min > target) {
        right = mid - 1;
      } else if (mid_max < target) {
        left = mid + 1;
      } else {
        left = right = mid;
      }
    }

    int index = left;

    left = 0, right = m - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (matrix[index][mid] == target) {
        return true;
      }
      if (matrix[index][mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return false;
  }
};

int main() {
  // 1 10 23
  // 11

  vector<vector<int>> nums = {
      {1, 2, 5},
      {10, 11, 20},
      {30, 32, 33}
  };
  cout << Solution().searchMatrix(nums, 34);

  return 0;
}
