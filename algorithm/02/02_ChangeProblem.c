#include "../../main.h"

// 找零问题（此实现为dp版，贪心版不限制硬币数量，从大减到小就完事了
// https://www.jianshu.com/p/d7cf201ecb72

// 需找零金额为M,给一些不同面值的硬币<a_{0},a_{1}.....a_{n}>，
//      要计算出找M所需要的最少硬币数
// dp[i] = dp(dp[i-coin] + 1) (i >= c)
/**
 * @param amount 金额
 * @param coins 硬币数组，默认升序，默认coins[0]=1
 * @param coinsNum 硬币种类数 / 硬币数组长度
 * */
 // 时间复杂度 O(mn)，空间复杂度 O(m)
int ChangeProblem(int amount, const int coins[], int coinsNum) {
    // dp[i] 表示凑金额i需要花费的硬币数
    int dp[amount + 1] = {};

    for (int i = 1; i <= amount; ++i) {
        // 初始化最少用到的硬币数，为 i/coins[0]
        // 一般题中 coins[0]=1，故初始时 min = i/1 = i
        int min = i;
        for (int j = 0; j < coinsNum; ++ j) {
            int coin = coins[j];
            if (i >= coin) {
                // 当前金额最少找零数量 = (前金额-硬币面值)的最少找零数量 + 1
                int minTemp = dp[i-coin] + 1;
                // 更新最小找零数，并在所有硬币枚举完后记入 dp[]
                if (minTemp < min) min = minTemp;
            }
        }
        dp[i] = min;
    }
    return dp[amount];
}

int main() {
    int value = 63;
    int coins[] = {1,5,10,25};
    int min = ChangeProblem(value, coins, sizeof(coins)/sizeof(coins[0]));
    printf("Min count: %d", min);
}