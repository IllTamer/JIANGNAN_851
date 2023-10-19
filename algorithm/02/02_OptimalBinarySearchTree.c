#include "../../main.h"

// 最优二叉搜索树
//      不好理解，记住公式
//      【最优二叉搜索树  动态规划算法】 https://www.bilibili.com/video/BV1Mw411k7wH
// w(i,j) = w(i,j-1)+b(j)+a(j)            w(i,i-1)=a(i-1)
// m(i,j) = w(i,j)+min{m(i,k-1)+m(k+1,j)} m(i,i-1)=0
/**
 * @param a 查找不成功概率
 * @param b 查找成功概率
 * @param m 存放最优比较次数
 * @param s 存放断开位置（树根）
 * @param w 存放概率和
 * */
void OptimalBinarySearchTree(int *a, int *b, int n, int **m, int **s, int **w) {
    // 初始化边界情况
    for (int i = 0; i <= n; ++i) {
        w[i + 1][i] = a[i]; // w(i,i-1)=a(i-1)
        m[i + 1][i] = 0;    // m(i,i-1)=0
    }

    // 控制问题规模，1->1、1->2、1->3
    for (int r = 1; r <= n; ++ r) {
        // 控制比较次数，i为每次的起始位置
        for (int i = 1; i <= n-r+1; ++ i) {
            // 每次结束位置
            int j = i+r-1;
            w[i][j] = w[i][j-1] + a[j] + b[j]; // w(i,j) = w(i,j-1)+b(j)+a(j)
            // 初始化 m[i][j]、断开位置
            m[i][j] = m[i+1][j]; // min{m(i,k-1)+m(k+1,j)}，此时k=i
            s[i][j] = i;
            // 寻找最优断开位置
            for (int k = i+1; k <= j; ++ k) {
                int temp = m[i][k-1]+m[k+1][j]; // min{m(i,k-1)+m(k+1,j)}
                if (temp < m[i][j]) {
                    m[i][j] = temp;
                    s[i][j] = k;
                }
                m[i][j] += w[i][j];             // m(i,j) = w(i,j) + min{}
            }
        }
    }
}