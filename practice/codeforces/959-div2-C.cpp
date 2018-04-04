//
// Created by liuzihe on 2018/4/4.
// Link: http://codeforces.com/contest/959/problem/C.
//

#include <iostream>
#include <cstdio>

using namespace std;

int n;

void print_incorrect_graph() {
    if (n <= 5) {
        printf("-1\n");
        return;
    }

    int even_deep_sum = n / 2;
    int odd_deep_sum = n - even_deep_sum;

    for (int i = 2; i <= odd_deep_sum + 1; i++) {
        printf("%d %d\n", 1, i);
    }

    for (int i = odd_deep_sum + 2; i <= n; i++) {
        printf("%d %d\n", 2, i);
    }
}

void print_correct_graph() {
    for (int i = 2; i <= n; i++) {
        printf("%d %d\n", 1, i);
    }
}

int main() {
    scanf("%d", &n);
    print_incorrect_graph();
    print_correct_graph();

    return 0;
}