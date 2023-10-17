#include "../../main.h"

#define INF (1e9+7)
int min(int a, int b) {
    return a < b ? a : b;
}

// 找零问题
// https://blog.csdn.net/Cowry5/article/details/100992653

// 需找零金额为M,给一些不同面值的硬币<a_{0},a_{1}.....a_{n}>，
//      要计算出找M所需要的最少硬币数
// dp[i] = min(dp[i], dp[i-coin]+1) (i >= c)

/**
 * 完全背包版（每个硬币可选无限次
 * @param amount 金额
 * @param coins 硬币数组，默认升序
 * @param coinsNum 硬币种类数 / 硬币数组长度
 * */
 // 时间复杂度 O(mn)，空间复杂度 O(m)
int ChangeProblem_Total(int amount, const int coins[], int coinsNum) {
    // dp[i] 表示凑金额i需要花费的硬币数
    int dp[amount + 1] = {};
    // 初始化数组，若结果是INF,则找不到目标数量
    for (int i = 1; i <= amount; ++ i) dp[i] = INF;
    // 从小到大遍历coin
     for (int coinIndex = 0; coinIndex < coinsNum; ++ coinIndex) {
         int coin = coins[coinIndex];
         // 从小到大计算dp[i] —— **重复选取硬币**
         // 从coin面值起计算找零 (i-coin >= 0)
         for (int i = coin; i <= amount; ++ i) {
             dp[i] = min(dp[i], dp[i-coin]+1);
         }
     }
    return dp[amount] == INF ? -1 : dp[amount];
}

/**
 * 01背包版（每个硬币最多选一次
 * @param amount 金额
 * @param coins 硬币数组，默认升序
 * @param coinsNum 硬币种类数 / 硬币数组长度
 * */
// 时间复杂度 O(mn)，空间复杂度 O(m)
int ChangeProblem_01(int amount, const int coins[], int coinsNum) {
    int dp[amount + 1] = {};
    for (int i = 1; i <= amount; ++ i) dp[i] = INF;

    for (int coinIndex = 0; coinIndex < coinsNum; ++ coinIndex) {
        int coin = coins[coinIndex];
        // 从大到小计算dp[i] —— **硬币仅选取一次**
        for (int i = amount; i >= coin; -- i) {
            dp[i] = min(dp[i], dp[i-coin]+1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

// 多重背包版（每个硬币数量有限
// TODO 超纲，理应不考

int main() {
    int value = 7;
    int coins[] = {2,5,10,25};
    int min = ChangeProblem_01(value, coins, sizeof(coins)/sizeof(coins[0]));
    printf("Min count: %d", min);
}