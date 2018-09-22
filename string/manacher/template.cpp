#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
const int STR_LEN = 110005;
char str[STR_LEN * 2];
// ans[i]: 位置i的最长回文子串的半径长度（包括自身）
// str    $ # a # b # a #
// index  0 1 2 3 4 5 6 7
// ans    - - 2 - 2 - 4 -
int ans[STR_LEN * 2];

int manacher() {
    // max_right_pos 为在遍历到当前位置，i + ans[i]最大的位置
    int len = strlen(str), max_right_pos = 0, max_len = 0;
    // $ # a # b # c #
    // 0 1 2 3 4 5 6 7
    //     0   1   2
    for(int i = len;i >= 0; --i) {
        str[i*2+2] = str[i];
        str[i*2+1] = '#';
    }
    str[0] = '$';
    for (int i = 2;i <= 2*len + 1; ++i) {
        if(ans[max_right_pos] + max_right_pos > i) {
            // ans[2*max_right_pos-i] 为相对于max_right_pos和i对称位置的最长回文子串长度
            // ans[max_right_pos] + max_right_pos 为能碰到的最右位置
            // 取ans[2*max_right_pos-i] 和 ans[max_right_pos] + max_right_pos - i最小即可
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
    while(scanf("%s", str) != EOF) {
        cout<<manacher()<<endl;
    }

    return 0;
}
