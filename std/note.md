### 反向迭代器

对于`vector<T> nums`，正向和反向迭代器示意图如图所示。。

- 正向迭代器为`nums.begin()`和`nums.end()`。
- 反向迭代器为`nums.rbegin()`和`nums.rend()`。

![rbegin_rend](./rbegin_rend.gif)

`nums.rbegin()`为最后一个元素，`nums.rend()`为第一个元素再往前的一个位置的元素（没有这个元素，只是边界条件，和`num.end()`类似）。

对于`auto iter = nums.rbegin()`，`iter+delta`为从iter位置向左前`delta`位置。

```c++
// 最后会输出：3 2 1
vector<int> nums = {1, 2, 3};
for (auto iter = nums.rbegin(); iter != nums.rend(); iter++) {
    cout << *iter << " ";
}
```

