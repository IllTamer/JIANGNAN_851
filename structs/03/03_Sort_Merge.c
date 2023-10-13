#include "../../main.h"

// 归并排序 —— 递归分治
// https://www.cnblogs.com/lanhaicode/p/11284230.html
void merge(int start, int middle, int end, int space[], int nums[]) {
    int index1 = start, index2 = middle;
    int sIndex = 0;
    // 两组共同比较赋值
    while (index1 < middle && index2 <= end) {
        space[sIndex++] = nums[
                    nums[index1] < nums[index2] ? index1++ : index2++
                ];
    }
    // 两组剩余赋值
    while (index1 < middle) space[sIndex ++] = nums[index1 ++];
    while (index2 <= end) space[sIndex ++] = nums[index2 ++];
    // 转移临时空间的数据
    for (int i = 0; i < sIndex; ++ i) nums[start+i] = space[i];
}
// 先拆分，后合并，注意中间索引(第二组起点)取值
void MergeSort(int nums[], int start, int end) {
    if (start >= end) return;
    // 此处向下取整，所以后续分组中间值应为 middle+1
    int middle = (start+end) / 2;
    // 自顶向下拆分数组 -> [start, middle] + [middle+1, end]
    MergeSort(nums, start, middle);
    MergeSort(nums, middle+1, end);
    // 申请新数组空间，长度为两数组之和
    int space[end-start+1];
    merge(start, middle+1, end, space, nums);
}


int main() {
    int nums[] = {9, 6, 7, 5, 8, 4, 1, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
    MergeSort(nums, 0, len-1);
    for (int i = 0; i < len; ++ i) {
        printf("%d ", nums[i]);
    }
}