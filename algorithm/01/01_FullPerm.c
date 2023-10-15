#include "../../main.h"

#define datatype int
void swap(datatype *a, datatype *b) {
    datatype temp = *b;
    *b = *a;
    *a = temp;
}

// 递归生成全排列
// 定义：从n个元素中任取m个元素，(m<=n)，按照一定的顺序排列起来，叫做
//      从n个不同元素中取出m个元素的一个排列，当m=n时，所有的排列情况称为全排列
// 思路：将整组数中的所有的数分别与第一个数交换，对其后面的元素进行全排列，
//      **并在每次排列后及时置换回元素**
void FullPerm(int start, int end, datatype data[]) {
    if (start == end) {
        // 排列结果必须在分支尾部输出
        // 递归就像树形图，一层一层往下分枝，若提前输出非叶子节点会出现重复结果
        for (int i = 0; i <= end; ++ i) printf("%d ", data[i]);
        printf("\n");
        return;
    }
    for (int i = start; i <= end; ++ i) {
        swap(&data[start], &data[i]);
        FullPerm(start+1, end, data);
        // 回溯 —— 每次排列后及时置换回元素
        swap(&data[start], &data[i]);
    }
}

int main() {
    datatype data[] = {1, 2, 3};
    FullPerm(0, sizeof(data)/sizeof(data[0])-1, data);
}