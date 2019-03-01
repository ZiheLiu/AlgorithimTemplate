#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
  int size;
  vector<int> nums;
  vector<int> sum;

  int x;
  int y;
  int ans;

  int build(int left, int right, int node_id) {
    if (left == right) {
      return sum[node_id] = nums[left];
    }

    int mid = left + (right - left) / 2;
    return sum[node_id] = build(left, mid, 2 * node_id) + build(mid + 1, right, 2 * node_id + 1);
  }

  void query(int left, int right, int node_id) {
    if (x <= left && right <= y) {
      ans += sum[node_id];
    } else {
      int mid = left + (right - left) / 2;
      if (x <= mid) {
        query(left, mid, node_id * 2);
      }
      if (y > mid) {
        query(mid + 1, right, node_id * 2 + 1);
      }
    }
  }

  void add(int left, int right, int node_id) {
    sum[node_id] += y;
    if (left != right) {
      int mid = left + (right - left) / 2;
      if (x <= mid) {
        add(left, mid, node_id * 2);
      } else {
        add(mid + 1, right, node_id * 2 + 1);
      }
    }
  }

public:
  NumArray(vector<int> nums) {
    this->nums = nums;
    this->size = nums.size();

    for (int i = 0; i < this->size * 4; i++) {
      this->sum.push_back(0);
    }

    if (this->size > 0) {
      build(0, this->size - 1, 1);
    }

  }

  void update(int i, int val) {
    x = i;
    y = val - nums[i];
    nums[i] = val;

    add(0, this->size - 1, 1);

    cout << endl;
  }

  int sumRange(int i, int j) {
    x = i;
    y = j;
    ans = 0;
    query(0, this->size - 1, 1);
    return ans;
  }
};

int main() {
  vector<int> nums = {7, 2, 7, 2, 0};
  auto item = NumArray(nums);
  item.update(4, 6);
  item.update(0, 2);
  item.update(0, 9);

  cout << item.sumRange(4, 4) << endl;

  item.update(3, 8);

  cout << item.sumRange(0, 4) << endl;

  return 0;
}
