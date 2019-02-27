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
 * 给定一个二维数组，每一行数字递增，每一列数字递增。问一个数字是否存在。
 * {
 *  {1, 5, 10},
 *  {11, 12, 21},
 *  {20, 22, 33}
 *  }
 */

/**
 * Hint:
 * 从左下角开始遍历即可。
 * 因为对于一个点，它上边的点比它小，它左边的点比它大。
 */

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int x = matrix.size() - 1, y = 0;
    while (x >= 0 && y < matrix[x].size()) {
      if (matrix[x][y] == target) {
        return true;
      }
      if (matrix[x][y] > target) {
        x--;
      } else {
        y++;
      }
    }

    return false;
  }
};

int main() {
  // 1 10 23
  // 11

  vector<vector<int>> nums = {
      {1, 5, 10},
      {11, 12, 21},
      {20, 22, 33}
  };
  cout << Solution().searchMatrix(nums, 10);

  return 0;
}
