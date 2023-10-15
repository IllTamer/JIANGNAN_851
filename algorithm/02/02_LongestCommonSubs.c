#include "../../main.h"

// 最长公共子序列
#define MAX_LEN 100
// dp[i][j] 表示text1的第i个字符和text2的第j个字符的最长公共子序列长度
int dp[MAX_LEN][MAX_LEN];

// 书上递归公式
//           0                          i>0;j=0
// c[i][j] = c[i-1][j-1]+1              i,j>0;x_i=y_i
//           max{c[i][j-1], c[i-1][j]}  i,j>0;x_i!=y_i

// O(mn)
void LCSLength(char *text1, char *text2) {
    for (int i = 0; i < strlen(text1); ++ i) {
        for (int j = 0; j < strlen(text2); ++ j) {
            int same = text1[i] == text2[j] ? 1 : 0;
            // 五种情况
            // 起点：直接判断
            if (i == 0 && j == 0) {
                dp[i][j] = same;
            // 两边边界：当前/与前一位是否相同 (<= 1)
            } else if (i == 0) {
                dp[i][j] = dp[i][j-1] || same;
            } else if (j == 0) {
                dp[i][j] = dp[i-1][j] || same;
            // 中间：相同则对角值+1,不同则继承两边最大值
            } else if (same) {
                dp[i][j] = dp[i-1][j-1] + same;
            } else {
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
}

// algorithm 与 competition 最长公共子序列为 oit(3)
int main() {
    char *text1 = "algorithm";
    char *text2 = "competition";
    LCSLength(text1, text2);
    printf("LCS: %d", dp[strlen(text1)-1][strlen(text2)-1]);
}