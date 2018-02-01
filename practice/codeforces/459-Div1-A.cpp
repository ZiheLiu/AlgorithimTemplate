#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX_N = 5005;

char str[MAX_N];
int res_left, question_count;
int ans = 0;

void init() {
    res_left = 0;
    question_count = 0;
}

// link: http://codeforces.com/contest/917/problem/A
int main() {
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        init();

        for (int j = i; j < len; j++) {
            if (str[j] == '(') {
                res_left++;
            } else if (str[j] == ')') {
                res_left--;
            } else {
                // 先把'?'当做')'计算
                res_left--;
                question_count++;
            }


            if (!res_left) {
                ans++;
            } else if (res_left < 0) {
                if (question_count <= 0) {
                    break;
                }
                // 如果')'数目多余'('，把一个'?'当做'('计算
                res_left += 2;
                question_count--;
            }
        }
    }

    cout << ans;

    return 0;
}