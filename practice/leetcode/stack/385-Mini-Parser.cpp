#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/**
 * 问题:
 * 给定一个字符串[[],[],-12,23,[-11],23]，返回一个NestedInteger。
 * NestedInteger可以为一个数字或者一个NestedInteger的列表。
 */

/**
 * Hint:
 * 维护一个当前节点cur，以及cur的祖先们组成的stack。
 */

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
private:
  int value;
  vector<NestedInteger> integers;
  bool is_integer;

public:
  // Constructor initializes an empty nested list.
  NestedInteger(): is_integer(false) {};

  // Constructor initializes a single integer.
  NestedInteger(int value): is_integer(true), value(value) {}

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const {
    return this->is_integer;
  }

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const {
    return this->value;
  }

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value) {
    this->is_integer = true;
    this->value = value;
  }

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni) {
    this->is_integer = false;
    this->integers.push_back(ni);
  }

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const {
    return this->integers;
  }
};

class Solution {
public:
  NestedInteger deserialize(string str) {
    // [123,[456,[789],234,45]]
    stack<NestedInteger> integers;

    NestedInteger root;
    NestedInteger& cur = root;
    int flag = 1;

    for (int i = 0; i < str.size(); i++) {
      char chr = str[i];
      switch (chr) {
        case ',':
          integers.top().add(cur);
          cur = NestedInteger();
          flag = 1;
          break;
        case '[':
          integers.push(cur);
          cur = NestedInteger();
          flag = 1;
          break;
        case ']':
          if (str[i - 1] != '[') {
            integers.top().add(cur);
          }
          cur = integers.top();
          integers.pop();
          flag = 1;
          break;
        case '-':
          flag = -1;
          break;
        default:
          int num;
          if (cur.isInteger()) {
            num = cur.getInteger();
          } else {
            num = 0;
          }
          cur.setInteger(num * 10 + flag * (chr - '0'));
      }
    }

    return root;
  }
};


int main() {
  NestedInteger res = Solution().deserialize("[[],[],-12,23,[-11],23]");
  return 0;
}
