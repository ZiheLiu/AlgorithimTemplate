#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

const int MAX_N = 10000;
int sum[MAX_N * 4];
int nums[MAX_N];

int build(int left, int right, int node_id) {
    if (left == right) {
        return sum[node_id] = nums[left];
    }
    int mid = left + (right - left) / 2;
    return sum[node_id] = build(left, mid, 2 * node_id) + build(mid + 1, right, 2 * node_id + 1);
}

int query(int left, int right, int node_id, int query_left, int query_right) {
    int ans = 0;
    if (query_left <= left && query_right >= right) {
        ans += sum[node_id];
    } else {
        int mid = left + (right - left) / 2;
        if (query_left <= mid) {
            ans += query(left, mid, node_id * 2, query_left, query_right);
        }
        if (query_right > mid) {
            ans += query(mid + 1, right, node_id * 2 + 1, query_left, query_right);
        }
    }
    return ans;
}

void add(int left, int right, int node_id, int add_value, int add_pos) {
    sum[node_id] += add_value;
    if (left == right) {
        return;
    }
    int mid = left + (right - left) / 2;
    if (add_pos <= mid) {
        add(left, mid, node_id * 2, add_value, add_pos);
    } else {
        add(mid + 1, right, node_id * 2 + 1, add_value, add_pos);
    }
}



int main() {
    int n, ops_sum, x, y, op;

    scanf("%d %d", &n, &ops_sum);
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
    }
    // 注意根节点node_id是1
    build(0, n - 1, 1);

    while (ops_sum--) {
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            // add
            add(0, n - 1, 1, y, x);
        } else {
            // query
            printf("%d\n", query(0, n - 1, 1, x, y));
        }
    }

    return 0;
}
