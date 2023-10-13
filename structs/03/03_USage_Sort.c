#include "../../main.h"

/**
 * 顺序结构线性表LA与LB的结点关键字为整数。LA与LB的元素按非递减有序，
 * 线性表空间足够大。试用类Pascal语言给出一种高效算法，将LB中元素合并到LA中，
 * 使新LA的元素仍保持非递减有序。高效指最大限度地避免移动元素
 * */
// 本题答案来自ChatGPT，逻辑结构清晰，推荐参考
// 解题思路：LA足够大，要求交换次数少，考虑直接倒序将排序后数值从后往前插入LA —— 归并排序归并思想
void MergeLists(int LA[], int LB[], int sizeLA, int sizeLB) {
    int i = sizeLA - 1;  // LA的末尾索引
    int j = sizeLB - 1;  // LB的末尾索引
    int k = sizeLA + sizeLB - 1;  // 合并后的LA的末尾索引

    // 从后往前遍历LA和LB，将较大的元素放入合并后的LA
    while (i >= 0 && j >= 0) {
        if (LA[i] >= LB[j]) {
            LA[k] = LA[i];
            i--;
        } else {
            LA[k] = LB[j];
            j--;
        }
        k--;
    }

    // 如果LB还有剩余元素，将其依次放入LA的前面
    while (j >= 0) {
        LA[k] = LB[j];
        j--;
        k--;
    }
}