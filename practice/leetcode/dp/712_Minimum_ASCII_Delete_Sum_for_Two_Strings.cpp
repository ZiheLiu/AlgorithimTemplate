#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 问题
 * 给定两个字符串（只有小写字母），每个字符串可以去除任意个字符。
 * 问两个字符串去除的字符的ASCII码之和最少为多少，可以使两个字符串相等？
 */

/**
 * dp[i][j]表示str[0, ..., i-1]和str[0, ..., j-1]的子问题。
 */

class Solution {
public:
  int minimumDeleteSum(string str1, string str2) {
    int size1 = str1.size(), size2 = str2.size();
    int dp[size1 + 1][size2 + 1];
    dp[0][0] = 0;
    for (int i = 1; i <= size1; i++) {
      dp[i][0] = dp[i - 1][0] + int(str1[i - 1]);
    }
    for (int i = 1; i <= size2; i++) {
      dp[0][i] = dp[0][i - 1] + int(str2[i - 1]);
    }

    for (int i = 1; i <= size1; i++) {
      for (int j = 1; j <= size2; j++) {
        if (str1[i - 1] == str2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i - 1][j - 1] + int(str1[i - 1]) + int(str2[j - 1]);
        }

        dp[i][j] = min(dp[i][j], dp[i - 1][j] + int(str1[i - 1]));
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + int(str2[j - 1]));
      }
    }

    return dp[size1][size2];
  }
};


int main() {

  cout << Solution().minimumDeleteSum("delete", "leet");
  return 0;
}
