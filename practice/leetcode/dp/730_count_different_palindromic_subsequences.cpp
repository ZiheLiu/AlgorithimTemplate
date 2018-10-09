#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int countPalindromicSubsequences(const string &str) {
        /**
         * dp[i][j]表示从str[i]到str[j]所包含的不同的回文子串长度.
         *
         * 在求dp[i][j]的时候,
         * - 如果str[i] != str[j], 则
         *      dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]
         * - 如果str[i] == str[j], 则（假设str[i]为x）
         *      找到在[i+1, j-1]范围内的，最外层的left和right, 使得str[left]==str[right]==str[i]
         *      - 如果left > right
         *          说明在[i+1, j-1]中没有找到和str[i]相同的字符，dp[i][j] = dp[i + 1][j - 1] * 2 + 2
         *          乘以2，是因为把[i+1, j-1]外层都套一个x，又是不同的回文序列了
         *          加2，是因为有x x和x两个回文序列
         *      - 如果left == right
         *          说明在[i+1, j-1]中只有一个和str[i]相同的字符，dp[i][j] = dp[i + 1][j - 1] * 2 + 1
         *          加1，是因为x这个回文序列在[i+1, j-1]中已经算过了
         *      - 如果left < right
         *          说明在[i+1, j-1]中找到了两个和str[i]相同的字符，dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1]
         *          减去dp[left + 1][right - 1]，是因为[left + 1, right-1]这部分的回文子序列的外层套一个x，
         *              在dp[i + 1][j - 1] * 2中计算了一次，
         *              在计算[left][right]中也计算了一次.
         */
        int size = str.length();
        int dp[size][size];

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < size; i++) {
            dp[i][i] = 1;
        }

        for (int i = size - 1; i >= 0; i--) {
            for (int j = i + 1; j < size; j++) {
                if (str[i] != str[j]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]) % MOD;
                } else {
                    int left = i + 1, right = j - 1;
                    while (left <= right && str[left] != str[i]) {
                        left++;
                    }
                    while (left <= right && str[right] != str[i]) {
                        right--;
                    }
                    if (left > right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (left == right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                    }
                    dp[i][j] %= MOD;
                }
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
        }

        return dp[0][size - 1];
    }
};

int main() {
    string str = "bbb";
    cout << Solution().countPalindromicSubsequences(str);
    return 0;
}
