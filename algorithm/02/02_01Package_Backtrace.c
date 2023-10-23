#include "../../main.h"

// 0-1 背包回溯法 —— 子集树
//      给定n种物品和一个背包，物品i的重量是wi,价值为vi,背包容量是c。
//      问如何选择装入背包的物品，使得装入的总价值最大

int n, // 物品数
c;     // 背包容量
float *w,    // 物品重量数组
*p,    // 物品价值数组
cW,    // 当前重量
cP,    // 当前价值
bestP; // 最优价值

// 分支界限函数，估计右孩子的最大价值
int bound(int i) {
    int cRight = c - cW; // 背包剩余容量
    int tempCP = cP; // 临时当前价值变量
    // 以物品单位重量价值降序 依次装入物品
    while (i <= n && w[i] <= cRight) {
        cRight -= w[i];
        tempCP += p[i];
        ++ i;
    }
    // 以当前单位价值装满剩余的背包
    // 贪心思想 —— 完全装不下后割掉部分装入
    if (i <= n)
        tempCP += (p[i]/w[i]) * cRight;
    return tempCP;
}

/**
 * 要求物品按单位重量价值降序排序
 * */
void backtrace(int i) {
    if (i > n) {
        bestP = cP;
        return;
    }
    // 重量合法 -> 进入左子树
    if (cW+w[i] <= c) {
        // 更新当前重量和当前价值，回溯
        cW += w[i]; // <1>
        cP += p[i]; // <2>
        backtrace(i+1);
        cP -= p[i]; // <2>
        cW -= w[i]; // <1>
    }
    // 贪心思想，估计最大价值，若价值不足自动剪枝 -> 进入右子树
    if (bound(i+1) > bestP) {
        backtrace(i+1);
    }
}