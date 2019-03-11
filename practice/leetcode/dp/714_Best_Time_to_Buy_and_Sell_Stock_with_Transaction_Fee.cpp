#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 问题
 * 给定一系列的一个货物的价格列表，可以买入或者卖出，卖出要付fee的交易费用。
 * 最多只能持有一个货物。
 * 问最多能赚多少钱？
 */

/**
 * dp[i][0]表示到第i个货物，没有持有货物的最多盈利。
 * dp[i][1]表示到第i个货物，持有货物的最多盈利。
 */


class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int size = prices.size();
    int dp[size + 2][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < size; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    return max(dp[size - 1][0], dp[size - 1][1]);
  }
};


int main() {

  vector<int> nums = {1, 3, 2, 8, 4, 9};

  cout << Solution().maxProfit(nums, 2);

  return 0;
}
