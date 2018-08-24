#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * https://www.hackerrank.com/challenges/sherlock-and-minimax/problem
 * 题意
 *  给定一个数组nums，一个范围内的数[p, q]
 *  对于[p,q]中的所有数pos， 求abs(nums[i] - pos)的最小值min_value。即每个pos对应一个min_value。
 *  求所有的min_value中的最大值，如果有多个，取pos最小的。
 */

/**
 * 解法
 *  把nums排序。
 *  对于nums[i]，
 *      设min_bound = (nums[i - 1] + nums[i]) / 2 + 1
 *      设max_bound = (nums[i] + nums[i + 1]) / 2
 *      在[min_bound, max_bound]范围内的pos的min_value = abs(nums[i] - pos)
 *  所以，遍历nums，求得每个nums[i]的[min_bound, max_bound]范围内的pos的min_value的最大值即可。
 */

const int kMaxN = 102;

int n, p, q;
int nums[kMaxN];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", nums + i);
    }
    scanf("%d%d", &p, &q);
}

int solve() {
    sort(nums + 1, nums + n + 1);
    nums[0] = -nums[1];

    int ans;
    int max_min_value = -1;
    for (int i = 1; i <= n; i++) {
        // [min_bound, max_bound]
        int min_bound = (nums[i - 1] + nums[i]) / 2 + 1;
        int max_bound;
        if (i == n) {
            max_bound = 1e9 + 10;
        } else {
            max_bound = (nums[i] + nums[i + 1]) / 2;
        }

        if (q < min_bound) {
            break;
        }

        if (min_bound >= p && min_bound <= q) {
            /**
             * p--------------q
             *    min_bound
             */
            int cur_max_min_value = abs(min_bound - nums[i]);
            if (cur_max_min_value > max_min_value) {
                max_min_value = cur_max_min_value;
                ans = min_bound;
            }
        } else if (p >= min_bound && p <= max_bound) {
            /**
             * min_bound--------------max_bound
             *              p
             */
            int cur_max_min_value = abs(p - nums[i]);
            if (cur_max_min_value > max_min_value) {
                max_min_value = cur_max_min_value;
                ans = p;
            }
        }

        if (max_bound >= p && max_bound <= q) {
            /**
             * p--------------q
             *    max_bound
             */
            int cur_max_min_value = abs(max_bound - nums[i]);
            if (cur_max_min_value > max_min_value) {
                max_min_value = cur_max_min_value;
                ans = max_bound;
            }
        } else if (q >= min_bound && q <= max_bound) {
            /**
             * min_bound--------------max_bound
             *              q
             */
            int cur_max_min_value = abs(q - nums[i]);
            if (cur_max_min_value > max_min_value) {
                max_min_value = cur_max_min_value;
                ans = q;
            }
        }
    }

    return ans;
}


int main() {
    freopen("../input", "r", stdin);
    input();
    printf("%d", solve());
    return 0;
}
