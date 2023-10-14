#include "../../main.h"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 二维最接近点问题
//      给定平面上n个点，找其中的一对点，使得在n个点组成的所有点对中，该点对的间距最小
// 点的数据结构
typedef struct {
    double x, y;
} Point;

// 按x升序排列
bool cmpX(Point *a, Point *b) {
    return a->x < b->x;
}
// 按y升序排列
bool cmpY(Point *a, Point *b) {
    return a->y < b->y;
}
double distance(Point *a, Point *b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

// https://blog.csdn.net/weixin_52629384/article/details/124940963
// O(nlogn)
// 将点按x升序排序，然后分治递归左右两侧分别获取最小距离，取最小者为dist，
//      收集所有x坐标在[middle-dist, middle+dist]的点，按y升序排序
//      寻找每个点 与其他点的y差值 不超过dist的区间，计算距离，取最小值
// 注意：默认输入points数组已按照x升序排序
double ClosestPont(int start, int end, Point **points) {
    if (start == end) return INFINITY;
    if (end-start == 1) return distance(points[start], points[end]);
    int middle = (start+end) / 2;
    // 找左右范围的最近距离
    double lMin = ClosestPont(start, middle, points);
    double rMin = ClosestPont(middle+1, end, points);
    // 取左右最近值作阈值
    double dist = min(lMin, rMin);
    int dLen = 0;
    Point *dPoints[end-start+1]; // 储存距离中间最近的一批点
    // 找里中间最近的点
    for (int i = start; i <= end; ++ i) {
        if (abs(points[i]->x - points[middle]->x) <= dist) {
            dPoints[dLen] = (Point *) malloc(sizeof(Point));
            dPoints[dLen ++] = points[i];
        }
    }
    // 按y值升序
    sort(dPoints, dPoints+dLen, cmpY);
    // 寻找每个点对应的y差值不超过d的区间，计算距离，取最小值（计算机算法设计与分析P31
    for (int i = 0; i < dLen; ++ i) {
        for (int j = i+1; j < dLen && abs(dPoints[i]->y - dPoints[j]->y) < dist; ++ j) {
            dist = min(dist, distance(dPoints[j], dPoints[i]));
        }
    }
    return dist;
}

//8
//1 1
//2 2
//4 4
//8 8
//2 2.8
//5 6
//7 9
//11 11
// 此代码改用cpp，便于实现按需排序
int main() {
    int len; cin >> len;
    Point *points[len];
    for (int i = 0; i < len; ++ i) {
        float x, y;
        cin >> x >> y;
        points[i] = (Point *) malloc(sizeof(Point));
        points[i]->x = x;
        points[i]->y = y;
    }
    // 将points按x升序排序
    sort(points, points+len, cmpX);
    double min = ClosestPont(0, len-1, points);
    printf("%.2f", min);
}
