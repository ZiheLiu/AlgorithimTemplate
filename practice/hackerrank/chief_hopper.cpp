#include <cstdio>

using namespace std;

/**
 * https://www.hackerrank.com/challenges/chief-hopper/problem
 */

/**
 * 题意
 *  有n + 1个柱子（0-n编号），柱子的高度依次为high[0]-high[n]
 *  机器人从第0个柱子依次跳到第n个柱子。
 *  从位置i跳到位置i + 1，机器人的能量为e，则机器人跳之后的能量为 e + (e - high[i])。
 *  必须跳之后的能量为非负数，才可以完成跳跃。
 *  求完成跳跃的最小能量数。
 */

/**
 * 题解
 *  e[i + 1] = 2 * e[i] - high[i]，
 *  所以 e[i] 为不小于 (e[i + 1] + high[i]) / 2 的最小正数。
 *  即e[i] = (e[i + 1] + high[i] + 1) / 2。
 *  所以设最后能量为0，从最后一个柱子，依次遍历到第一个柱子，即可。
 */

const int kMaxN = 1e5 + 2;
int n;
int nums[kMaxN];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
    }
}

void solve() {
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = (ans + nums[i] + 1) / 2;
    }
    printf("%d", ans);
}

int main() {
    input();
    solve();
    return 0;
}