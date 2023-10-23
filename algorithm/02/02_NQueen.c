#include "../../main.h"

int abs(int n) {
    return n < 0 ? -n : n;
}

// n后问题 —— 排列树
//      在n*n的棋盘上放置n个皇后，任意两皇后不在同一行&&同一列&&同一斜线
//      上，求符合的方案数

int sum, // 表示可行的方案数
*x,      // x[i]表示在第i行放置的列
n;       // 棋盘大小 n*n

// 检验第r行，是否和前面的行冲突
int place(int r) {
    for (int i = 1; i < r; ++ i) {
        // abs(r-i) == abs(x[r]-x[i]) 纵坐标只差绝对值==横坐标只差绝对值，在同一斜线
        // x[i] == x[r] 第i行与第r行在同一列
        if (abs(r-i) == abs(x[r]-x[i]) || x[i] == x[r])
            return -1;
    }
    return 0;
}
/**
 * @param r 递归到第r行
 * */
void backtrace(int r) {
    // 递归终止，解+1
    if (r > n) {
        ++ sum;
        return;
    }
    // 对于前面的第r行，选择一列放置皇后，进入下一层
    for (int i = 1; i <= n; ++ i) {
        x[r] = i;
        // 校验合法性
        if (place(r) == 0) backtrace(r+1);
    }
}