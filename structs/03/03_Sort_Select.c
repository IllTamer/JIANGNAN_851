#include "../../main.h"

// 选择排序
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

// 简单选择排序
// https://www.runoob.com/w3cnote/selection-sort.html
// 在未排序序列中找到最小元素，放到排序序列末尾
int* SelectionSort(int nums[], int len) {
    for (int i = 0; i < len; ++ i) {
        int minIndex = i;
        // 排序序列为 [0, i-1]
        for (int j = i; j < len; ++j) {
            if (nums[j] < nums[minIndex]) minIndex = j;
        }
        // 交换最小值
        int temp = nums[i];
        nums[i] = nums[minIndex];
        nums[minIndex] = temp;
    }
    return nums;
}

// 堆排序

// 下标为 i 的节点 左孩子下标 i*2+1
//               右孩子下标 左孩子下标+1
// 第一个非叶子节点 i/2-1
// 创建最大堆
void maxHeap(int nums[], int start, int end) {
    // 最大堆根(父)节点索引为start
    int dad = start;
    int son = dad*2 + 1;
    while (son <= end) {
        // 找最大的孩子节点
        if (son+1 <= end && nums[son] < nums[son+1]) ++ son;
        // 如果最大堆合规，则结束，不合规则交换父子节点，并继续循环
        if (nums[dad] > nums[son]) break;
        swap(&nums[dad], &nums[son]);
        dad = son;
        son = 2*dad + 1;
    }
}
// 生产最大堆，堆顶索引为0，从后向前倒序生成结果，并缩小堆直至1
int* HeapSort(int nums[], int len) {
    // 从第一个非叶子节点起创建最大堆
    for (int i = len/2-1; i > 0; -- i)
        maxHeap(nums, i, len-1);
    for (int i = len-1; i > 0; -- i) {
        // 从后向前将堆顶的值（最大值）归位，并调整堆
        swap(&nums[i], &nums[0]);
        maxHeap(nums, 0, i-1);
    }
    return nums;
}

int main() {
    int nums[] = {9, 6, 7, 5, 8, 4, 1, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
//    int *result = SelectionSort(nums, len);
    int *result = HeapSort(nums, len);
    for (int i = 0; i < len; ++ i) {
        printf("%d ", result[i]);
    }
}