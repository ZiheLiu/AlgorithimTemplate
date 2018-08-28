#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/**
 * 最长公共子序列。
 * 对于word1和word2，求最长公共子序列。
 * dp[i][j]代表，word1到i下标这个位置，word2到j下标这个位置，所能得到的最长公共子序列。
 *
 * 对于dp[i][j]，
 *  - 如果word1[i] == word2[j]，说明把这个相同的字符放在dp[i-1][j-1]后边即可组成一个长度大一的最长公共子序列。
 *      所以dp[i][j] = dp[i - 1][j - 1]
 *  - 如果word1[i] != word2[j]，则答案会出现在dp[i - 1][j]和dp[i][j - 1]之中。
 *      所以dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]
 *
 * 这个算法的时间复杂度为O(nm)的，如果word1和word2的字符是均匀分配的，可以转化为LIS的问题进行处理，时间复杂度为O(nlogn)。
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.length(), size2 = word2.length();
        int size = size1 + size2;

        int dp[size1 + 1][size2 + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return size - 2 * dp[size1][size2];
    }
};

int main() {
    auto num = Solution().minDistance("", "eat");
    cout << num;
}
