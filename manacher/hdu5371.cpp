#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <memory.h>

using namespace std;
const int STR_LEN = 1e5 + 5;
int str[STR_LEN * 2];
int ans[STR_LEN * 2];

int T,n;

// exercise link: http://acm.hdu.edu.cn/showproblem.php?pid=5371
int manacher() {
    int len = n, max_right_pos = 0, max_len = 0;
    // $ # a # b # c #
    // 0 1 2 3 4 5 6 7
    //     0   1   2
    for(int i = len;i >= 0; --i) {
        str[i*2+2] = str[i];
        str[i*2+1] = -1;
    }
    str[0] = -2;
    for (int i = 2;i <= 2*len + 1; ++i) {
        if(ans[max_right_pos] + max_right_pos > i) {
            ans[i] = min(ans[2*max_right_pos-i], ans[max_right_pos] + max_right_pos - i);
        }
        else {
            ans[i] = 1;
        }
        while(str[i-ans[i]] == str[i+ans[i]]) {
            ++ ans[i];
        }
        if (max_right_pos + ans[max_right_pos] < i + ans[i]) {
            max_right_pos = i;
        }
        if (max_len<ans[i]) {
            max_len = ans[i];
        }
    }
    return max_len - 1;
}


int main()
{
    scanf("%d", &T);
    for(int cur_case = 1; cur_case <= T; ++cur_case) {
        scanf("%d", &n);
        memset(str, -1, sizeof(str));
        for (int i = 0; i < n; i++) {
            scanf("%d", str + i);
        }
        manacher();
        int max_ans = 0;
        for (int i = 1; i <= 2*n + 1; i+=2) {
            for (int len = ans[i] - 1;len > max_ans; len -= 2) {
                if (ans[i+len]-1>=len) {
                    max_ans = len;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", cur_case, max_ans / 2 * 3);
    }

    return 0;
}
