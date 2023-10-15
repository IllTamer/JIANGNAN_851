#include "../../main.h"

// 矩阵连乘
// 问题背景：矩阵乘法满足结合律，不同计算次序数乘次数不同，如
//      A1(10x100) A2(100x5) A3(5x50)
//      (A1A2)A3 = 10x100x5 + 10x5x50 = 7500
//      A1(A2A3) = 100x5x50 + 10x100x50 = 75000
// 由 A1A2A3A4 的次数 = A1xA2的次数 + A3A4 的次数 + A1A2xA3A4的次数
//      （n个矩阵要数乘n-1次），可得
// m[i][j] = m[i][k] + m[k+1][j] + p_(i-1)*p_k*p_j (i < j)
//         = 0 (i = j)
// m[i][j] 代表 AiAi+1Ai+2...Aj (1 <= i <= j <= n)
/**
 * 时间复杂O(n^3)，空间复杂度O(n^2)
 * @param p 矩阵维数（维数重复索引相同
 * @param n 矩阵个数
 * @param m 储存最优结果的数组
 * */
void MatrixChain(const int p[], int n, int **m) {
    // 初始化特殊情况
    for (int i = 1; i <= n; ++ i) m[i][i] = 0;
    // 计算的范围，len即要连乘的矩阵的长度，len=2即A1A2、A2A3...
    for (int len = 2; len <= n; ++ len) {
        // 从第i个矩阵开始
        for (int i = 1; i <= n - len + 1; ++ i) {
            // 到第j个矩阵结束
            int j = i + len - 1;
            // 初始化断开点k=i+1，计算并储存最优结果(自底向上)
            //      Aij = A(i+1)j + 两矩阵相乘的p
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
            // 从第i+i个矩阵开始，尝试所有可能的断开点k
            for (int k = i+1; k < j; ++ k) {
                // 计算并更新m
                int min= m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (min < m[i][j]) {
                    m[i][j] = min;
                }
            }
        }
    }
}

int main() {
    int n = 6;
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int **m = (int **) malloc(sizeof(int *)*(n+1));
    for (int i = 0; i < n+1; ++ i) m[i] = (int *) malloc(sizeof(int)*(n+1));

    MatrixChain(p, n, m);

    printf("result: %d\n", m[2][5]);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j)
            printf("%8d", m[i][j]);
        printf("\n");
    }
}