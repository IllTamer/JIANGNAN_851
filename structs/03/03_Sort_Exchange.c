#include "../../main.h"

// 交换排序

// 冒泡排序
// 二重遍历，两两比较，谁大前移
// https://www.runoob.com/w3cnote/bubble-sort.html
int* BubbleSort(int nums[], int len) {
    // 一共len-1个两两比较
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1; ++j) {
            if (nums[j] > nums[j+1]) {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    return nums;
}

// 快速排序
// https://www.runoob.com/w3cnote/quick-sort-2.html#C++
// 分区函数，将数据划分至基准点两侧
int partition(int nums[], int low, int high) {
    // 记录基准点，此时出现一个中转节点
    int pivot = nums[low];
    while (low < high) {
        // 从高找直到找到一个比基准点小的，记录到低中转节点中
        while (low < high && nums[high] >= pivot) --high;
        nums[low] = nums[high];
        // 从低找直到找到一个比基准点大的，记录到高中转节点中
        while (low < high && nums[low] <= pivot) ++low;
        nums[high] = nums[low];
    }
    // low=分区结束位置=高&低中转节点
    nums[low] = pivot;
    return low;
}
// 主函数，分区递归
int* QuickSort(int nums[], int low, int high) {
    if (low >= high) return NULL;
    // 分区函数找基准值
    int pivot = partition(nums, low, high);
    QuickSort(nums, low, pivot-1);
    QuickSort(nums, pivot+1, high);
    return nums;
}

int main() {
    int nums[] = {9, 6, 7, 5, 8, 4, 1, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
//    int *result = BubbleSort(nums, len);
    int *result = QuickSort(nums, 0, len-1);
    for (int i = 0; i < len; ++ i) {
        printf("%d ", result[i]);
    }
}