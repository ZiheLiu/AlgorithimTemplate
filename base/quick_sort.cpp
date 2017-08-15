#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void quick_sort(int *nums, int left, int right) {
    if(left < right) {
        int i = left, j = right, base = nums[left];
        while(i < j) {
            while(i < j && nums[j] >= base) {
                --j;
            }
            if(i < j) {
                nums[i++] = nums[j];
            }
            while(i < j && nums[i] <= base) {
                ++i;
            }
            if (i < j) {
                nums[j--] = nums[i];
            }
        }
        nums[i] = base;
        quick_sort(nums, left, i - 1);
        quick_sort(nums, i + 1, right);
    }

}

int main() {

    int len;
    int nums[1000];
    cin >> len;
    for(int i = 0; i < len; i++) {
        cin >> nums[i];
    }
    quick_sort(nums, 0, len - 1);
    for(int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
