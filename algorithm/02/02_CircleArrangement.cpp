#include "../../main.h"
#include <algorithm>
#include <cmath>

using namespace std;

// 圆排列问题 - 排列树
// https://www.cnblogs.com/pgokc13/p/15715629.html
//      给定n个大小不等的圆，现要将这n个圆排进一个矩形框中，且要求各圆与矩形框底边相切。
//      求从n个圆的所有排列中找出有最小长度的圆排列

int n;     // 待排列的圆的个数
float Min, // 最优值
*x,        // 当前圆排列圆心横**坐标**
*r;        // 当前圆排列，储存的是圆的半径长

// 计算当前圆排列的长度
//      找所有圆的最左边与最右边，计算长度
void compute() {
    float low = 0, high = 0;
    for (int i = 1; i <= n; ++ i) {
        low = min(x[i]-r[i], low); // x[i]-r[i]是每个圆的最左边
        high = max(x[i]+r[i], high); // x[i]+r[i]是每个圆的最右边
    }
    Min = min(high-low, Min);
}
// 计算当前所选圆的圆心横坐标
float center(int i) {
    float temp = 0;
    // 遍历每一个排在之前的圆，假定相切，找到横坐标差值最大值
    for (int j = 1; j < i; ++ j) {
        // x^2 = sqrt((r1+r2)^2-(r2-r1)^2)
        //     = 2*sqrt(r1*r2)
        float valueX = x[j] + 2*sqrt(r[i]*r[j]);
        temp = max(valueX, temp);
    }
    return temp;
}

void backtrace(int i) {
    if (i > n) {
        compute();
        return;
    }
    // 从剩余的圆中任选一个放在第i个位置上
    for (int j = i; j <= n; ++ j) {
        swap(r[i], r[j]); // <1>
        float centerX = center(i);
        // 粗略估计判断 —— 减小剪枝代价
        // 右边界：当前圆心位置+当前圆半径 centerX+r[i]
        // 左边界：第一个圆的圆心坐标-第一个圆的半径 x[1]-r[1]
        if (centerX+r[i]+r[1] < Min) {
            x[i] = centerX;
            backtrace(i+1);
        }
        swap(r[i], r[j]); // <1>
    }
}