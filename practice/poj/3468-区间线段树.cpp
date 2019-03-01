#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 区间上线段树。
 * 每次把一个区间[x, y]上所有的数都增加val。
 * 
 * 每个节点维护一个lazy变量，为还没有传递给子节点的增加量。
 * 
 * 在update的时候，
 *  - 如果[x, y]覆盖了当前区间，则当前区间的sum增加val * length，lazy增加val。
 *  - 否则，先push down，查看[x, y]是否含有当前节点的左右子节点的区间，有则在子节点调用update。
 *  
 *  
 * 在query的时候，
 *  - 如果[x, y]覆盖了当前区间，则ans增加当前区间的sum。
 *  - 否则，先push down，查看[x, y]是否含有当前节点的左右子节点的区间，有则在子节点调用query。
 */
 


#define LL long long
#define MAX_N 100005

LL nums[MAX_N];

struct Node {
  LL left, right;
  LL sum, lazy;
}nodes[MAX_N * 4];

LL ans;
LL n, q, x, y, val;


LL build(LL node_id, LL left, LL right) {
  nodes[node_id].left = left;
  nodes[node_id].right = right;
  nodes[node_id].lazy = 0;

  if (left == right) {
    return nodes[node_id].sum = nums[left];
  } else {
    LL mid = (left + right) / 2;
    return nodes[node_id].sum = build(node_id * 2, left, mid) + build(node_id * 2 + 1, mid + 1, right);
  }
}


void push_down(LL node_id) {
  Node &node = nodes[node_id];
  Node &left_node = nodes[node_id * 2];
  Node &right_node = nodes[node_id * 2 + 1];

  left_node.lazy += node.lazy;
  right_node.lazy += node.lazy;
  left_node.sum += (left_node.right - left_node.left + 1) * node.lazy;
  right_node.sum += (right_node.right - right_node.left + 1) * node.lazy;

  node.lazy = 0;
}

void update(LL node_id, LL left, LL right, LL delta) {
  Node &node = nodes[node_id];
  if (left <= node.left && node.right <= right) {
    node.lazy += delta;
    node.sum += (node.right - node.left + 1) * delta;
  } else {
    push_down(node_id);

    LL mid = (node.left + node.right) / 2;
    if (left <= mid) {
      update(node_id * 2, left, right, delta);
    }
    if (right > mid) {
      update(node_id * 2 + 1, left, right, delta);
    }
    node.sum = nodes[node_id * 2].sum + nodes[node_id * 2 + 1].sum;
  }
}


void query(LL node_id, LL left, LL right) {
  Node &node = nodes[node_id];
  if (left <= node.left && node.right <= right) {
    ans += node.sum;
  } else {
    if (node.lazy != 0) {
      push_down(node_id);
    }
    LL mid = (node.left + node.right) / 2;
    if (left <= mid) {
      query(node_id * 2, left, right);
    }
    if (right > mid) {
      query(node_id * 2 + 1, left, right);
    }
  }
}


int main() {
  char option[5];
  scanf("%lld%lld", &n, &q);
  for (LL i = 0; i < n; i++) {
    scanf("%lld", nums + i);
  }

  build(1, 0, n - 1);

  for (LL i = 0; i < q; i++) {
    scanf("%s", option);
    if (option[0] == 'Q') {
      scanf("%lld%lld", &x, &y);
      ans = 0;
      query(1, x - 1, y - 1);
      printf("%lld\n", ans);
    } else {
      scanf("%lld%lld%lld", &x, &y, &val);
      update(1, x - 1, y - 1, val);
    }
  }


  return 0;
}
