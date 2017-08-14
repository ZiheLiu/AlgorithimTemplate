#include <iostream>
#include <cstdio>
#include <memory>
#include <cstring>

using namespace std;

// link http://poj.org/problem?id=1961
const int STR_LEN = 1e6 + 2;
int nextt[STR_LEN];
char str[STR_LEN];

void kmp() {
    memset(nextt, 0, sizeof(nextt));
    nextt[0] = -1;
    for(int i = 1; str[i] != 0; i++) {
        int j = nextt[i - 1];
        while(str[j + 1] != str[i] && j >= 0) {
            j = nextt[j];
        }
        if(str[j + 1] == str[i]) {
            nextt[i] = j + 1;
        }
        else {
            nextt[i] = -1;
        }
    }
}


int main() {
    int len, cur_case = 1;
    while(scanf("%d", &len) != EOF && len) {
        scanf("%s", str);
        kmp();
        printf("Test case #%d\n", cur_case++);
        for(int i = 0; i < len; i++) {
            if(nextt[i] != -1 && (i + 1) % (i - nextt[i]) == 0) {
                printf("%d %d\n", i + 1, (i + 1) / (i - nextt[i]));
            }
        }
        printf("\n");
    }

    return 0;
}
