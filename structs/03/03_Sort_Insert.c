#include "../../main.h"

// 插入排序

// 直接插入排序
// 依次遍历，将记录查到先前已排好序的有序表中
int* DirectSort(int nums[], int len) {
    if (len <= 1) return NULL;
    // 从第二项开始遍历
    for (int i = 1; i < len; ++ i) {
        // 找到乱序起点
        if (nums[i] < nums[i-1]) {
            // 倒序依次交换当前项与前一项数值直到起点 / 顺序合适
            for (int j = i; j != 0 && nums[j] < nums[j-1]; -- j) {
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
        }
    }
    return nums;
}

// 折半插入排序
//

// 希尔排序 —— 缩小增量排序
// 减小每次直接插入排序的步进值，直至为1
int* ShellSort(int nums[], int len) {
    for (int gap = len/2; gap > 0; gap /= 2) {
        // 以gap为步进值分组(共计len-gap组)，做直接插入排序
        for (int i = 0; i < len-gap; ++ i) {
            // i, i+gap, i+2gap ...
            for (int j = i; j+gap < len && nums[j] > nums[j+gap]; j += gap) {
                int temp = nums[j];
                nums[j] = nums[j+gap];
                nums[j+gap] = temp;
            }
        }
    }
    return nums;
}

int main() {
    int nums[] = {9, 6, 7, 5, 8, 4, 1, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
//    int *result = DirectSort(nums, len);
    int *result = ShellSort(nums, len);
    for (int i = 0; i < len; ++ i) {
        printf("%d ", result[i]);
    }
}