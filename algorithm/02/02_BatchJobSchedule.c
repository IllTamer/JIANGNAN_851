#include "../../main.h"

int max(int a, int b) {
    return a > b ? a : b;
}
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}


// 批处理作业调度 —— 排列树
//      要求从n个作业的所有排列中找出有最小完成时间的作业调度
//      每个作业先由机器1处理，再由机器2处理

// 排列树 https://www.cnblogs.com/youxin/p/4316325.html
//      当所给问题是确定n个元素满足某种性质的排列时，相应的解空间树称为排列树。
//      排列树通常有n!个叶子节点。因此遍历排列树需要O(n!)的计算时间。
//void backtrack (int t)
//{
//    if (t>n) output(x);
//    else
//        for (int i=t;i<=n;i++) {
//            swap(x[t], x[i]);
//            if (legal(t)) backtrack(t+1);
//            swap(x[t], x[i]);
//        }
//}

int **M, // M[i][j]表示i号作业在j号机器上所需的处理时间
*x,      // x[j]表示执行顺序为j的任务对应的编号为x[j]
*bestX,  // 最优作业调度的顺序安排
f1,      // 机器1完成处理时间
*f2,     // 机器2完成处理时间
f,       // 完成时间和
bestF,   // 完成时间和最优值
n;       // 作业数

/**
 * @param i 表示第i个作业，即递归到第i层
 * */
void backtrace(int i) {
    // 到达叶子节点，由于下文 f < bestF 的限制，此叶子节点必最优，直接更新即可
    if (i > n) {
        for (int j = 1; j <= n; ++ j) bestX[j] = x[j];
        bestF = f;
        return;
    }
    // 从i开始遍历每个作业，处理分支，j为任务的执行顺序
    for (int j = i; j <= n; ++ j) {
        // 更新机器1完成当前作业的时刻
        f1 += M[x[j]][1]; // <1>
        // 更新机器2完成当前作业的时刻
        f2[i] = max(f2[i-1], f1) + M[x[j]][2];
        f += f2[i]; // <2>
        // 如果有可能成为最优解，将j处作业交换到i处，深度搜索
        if (f < bestF) {
            swap(&x[i], &x[j]); // <3>
            backtrace(i+1);
            swap(&x[i], &x[j]); // <3>
        }
        f1 -= M[x[j]][1]; // <1>
        f -= f2[i]; // <2>
    }
}

int main() {

}