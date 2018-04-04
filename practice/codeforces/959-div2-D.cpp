//////
////// Created by liuzihe on 2018/4/4.
////// Link: http://codeforces.com/contest/959/problem/D.
//////
#include <iostream>
#include <cstdio>

/**
 * ## 问题
 * 给出一个数组，求一个数组，使得这个数组满足：
 *  1. 字典序大于原数组
 *  2. 数组的元素两两互质
 *
 * ## 解法
 * 设置数组visited[i], 每次只能取visited[i]为false的数字。
 * 当确定一个数组元素的时候，把这个数组元素所有因子x, 以及x^n都设为true。
 *
 * 遍历原数组，对于nums[i]，看当前是否还是处于与原数组相等的状态。
 * - 如果还是相等的状态，从nums[i]开始遍历，根据visited[i]选出可选的元素num, 把num的所有因子x, 以及x^n都设为true。
 * - 如果不相等状态，则每次从visited[i]中选取第一个为false的数字即可。
 *   注意，因为这个时候，每次选取的数字num都是比之前选取的数字大的。
 *   所以，并不用把num的所有因子x, 以及x^n都设为true（因为visited[x]为true，必然已经都弄过了）。
 *   所以只要把num^n设为true即可。
 *
 * 注意，因为要设visited数组的上界，所以要暴力算一下，2e5个互质数的最大数，来作为上界。
 */

using namespace std;

const int MAX_N = 1399709;
bool visited[MAX_N];

int n;
int num;
int usable_nums_begin = 2;
bool isEqual = true;

int get_next_usable_num(int start) {
    for (int j = start; j < MAX_N; j++) {
        if (!visited[j]) {
            return j;
        }
    }
}

void set_visited(int start) {
    if (!visited[start]) {
        for (int i = start; i < MAX_N; i+=start) {
            visited[i] = true;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);

        if (isEqual) {
            int cur = get_next_usable_num(num);

            printf("%d ", cur);

            if (cur != num) {
                isEqual = false;
            }


            for (int j = 2; j * j <= cur; j++) {
                // 找到cur的因子
                if (cur % j == 0) {
                    while (cur % j == 0) {
                        cur /= j;
                    }
                    set_visited(j);
                }
            }
            if (cur > 1) {
                set_visited(cur);
            }
        } else {
            int cur = get_next_usable_num(usable_nums_begin);
            usable_nums_begin = cur + 1;

            printf("%d ", cur);

            set_visited(cur);
        }
    }
}

// 求2e5个互质数，最大的为多少
//
//const int MAX_N = 1e5 + 5;
//
//int nums[MAX_N];
//bool visited[(int)1e8];
//
//int main() {
//    int cur = 2;
//    for (int i = 0; i < 2e5; i++) {
//        while (visited[cur]){cur++;}
//        for (int j = cur; j < 1e8; j+=cur) {
//            visited[j] = true;
//        }
//        cout << cur << " ";
//        if (i % 20 == 0) {
//            cout << endl;
//        }
//    }
//
//    cout << "end" <<endl;
//
//    cout << cur;
//    return 0;
//}