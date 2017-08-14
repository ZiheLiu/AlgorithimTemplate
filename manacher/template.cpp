#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;
const int STR_LEN = 110005;
char str[STR_LEN * 2];
int ans[STR_LEN * 2];

int manacher() {
    int len = strlen(str), max_right_pos = 0, max_len = 0;
    for(int i = len;i >= 0; --i) {
        str[i*2+2] = str[i];
        str[i*2+1] = '#';
    }
    str[0] = '$';
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
    while(scanf("%s", str) != EOF) {
        cout<<manacher()<<endl;
    }

    return 0;
}
