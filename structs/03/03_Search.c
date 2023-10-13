#include "../../main.h"

// 顺序查找 —— 遍历
// O(n)

// 二分/折半查找 —— 二分法
// O(log2n)
// 递归
int BinarySearch_Recursion(int start, int end, const int nums[], int target) {
    if (start > end) return -1;
    if (start == end)
        return nums[start] == target ? start : -1;
    int middle = (start+end) / 2;
    if (nums[middle] == target) return middle;
    if (nums[middle] > target)
        return BinarySearch_Recursion(start, middle-1, nums, target);
    else
        return BinarySearch_Recursion(middle+1, end, nums, target);
}
// 非递归 —— 双指针
int BinarySearch(const int nums[], int len, int target) {
    int start = 0, end = len-1;
    while (start <= end)
    {
        if (start == end)
            return nums[start] == target ? start : -1;
        int middle = (start+end) / 2;
        if (nums[middle] == target) return middle;
        if (nums[middle] > target)
            end = middle-1;
        else
            start = middle+1;
    }
    return -1;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(nums)/sizeof(nums[0]);
    int result ;
    result = BinarySearch_Recursion(0, len-1, nums, 5);
    printf("index=%d\n", result);
    result = BinarySearch(nums, len, 5);
    printf("index=%d\n", result);
}