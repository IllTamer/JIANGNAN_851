#include "../../main.h"

// 大整数乘法 —— 分治
// O(n^2)表格法：https://blog.csdn.net/m0_70058994/article/details/124567732
// O(n^1.59)：https://www.cnblogs.com/McQueen1987/p/3348426.html
//      X = Ax10^(n/2)+B，Y = Cx10^(n/2)+D （n为X、Y的最大位数
//      XY = ACx10^n + (AD+BC)x10^(n/2) + BD
//      要注意该大数乘法还涉及到大数加法，要理解思想
