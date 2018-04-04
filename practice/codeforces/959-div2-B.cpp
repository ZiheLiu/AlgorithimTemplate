//
// Created by liuzihe on 2018/4/4.
// Link: http://codeforces.com/contest/959/problem/B.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

const int MAX_N = 1e5 + 2;
int words_sum, groups_sum, msgs_sum;
string words[MAX_N];
int wordCost[MAX_N];
unordered_map<string, int> map_word_to_index;

int cur_group_items_sum;
int cur_group_items[MAX_N];

string msg;
int tmp;

int main() {
    scanf("%d%d%d", &words_sum, &groups_sum, &msgs_sum);
    for (int i = 0; i < words_sum; i++) {
        cin >> words[i];
        map_word_to_index[words[i]] = i;
    }

    for (int i = 0; i < words_sum; i++) {
        scanf("%d", wordCost + i);
    }

    for (int i = 0; i < groups_sum; i++) {
        scanf("%d", &cur_group_items_sum);
        int min_cost = 1e9 + 5;
        for (int j = 0; j < cur_group_items_sum; j++) {
            scanf("%d", &tmp);
            cur_group_items[j] = tmp - 1;
            if (min_cost > wordCost[cur_group_items[j]]) {
                min_cost = wordCost[cur_group_items[j]];
            }
        }

        for (int j = 0; j <cur_group_items_sum; j++) {
            wordCost[cur_group_items[j]] = min_cost;
        }
    }

    long long ans = 0;
    for (int i = 0; i < msgs_sum; i++) {
        cin >> msg;
        ans += (wordCost[map_word_to_index[msg]]);
    }

    cout << ans;
}