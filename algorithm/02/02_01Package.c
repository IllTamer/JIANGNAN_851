#include "../../main.h"

int max(int a, int b) {
    return a > b ? a : b;
}

// 0-1背包问题
// 给定n种物品和一个背包，物品i的重量是wi,价值为vi,背包容量是c。
//      问如何选择装入背包的物品，使得装入的总价值最大
// http://c.biancheng.net/algorithm/01-knapsack.html

// m(i,j) = max{m(i-1,j), m(i-1,j-wi)+vi} j>=wi
//          m(i-1,j)                      0<=j<wi

// O(nc)
// O(min{nc, 2^n})算法较难记忆，有需求者自行拓展
#define N 5 // 物品种类
#define C 11 // 背包容量
int dp[N+1][C+1]; // dp[i][j] 表示考虑前i件物品，有j的背包容量
/**
 * @param weight 物品重量
 * @param value 物品价值
 * */
void Knapsack01(const int weight[], const int value[]) {
    // 遍历每件物品
    for (int i = 1; i <= N; ++i) {
        // 计算 1->C 各个容量的最大收益
        for (int j = 1; j <= C; ++j) {
            // 背包载重量 < 商品总重量，不放
            if (j < weight[i])
                dp[i][j] = dp[i-1][j];
            else
                // 比较装入该商品和不装该商品，哪种情况获得的收益更大，记录最大收益值
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        }
    }
}

int main() {
    int weight[] = {-1, 1, 2, 5, 6, 7};
    int value[] = {-1, 1, 6, 18, 22, 28};
    Knapsack01(weight, value);
    printf("Max value: %d", dp[N][C]);
}