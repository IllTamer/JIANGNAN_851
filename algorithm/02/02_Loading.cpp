#include "../../main.h"
#include <iostream>
#include <algorithm>

using namespace std;

// 最优装载
//      有一批集装箱要装上一艘载重为c的轮船，其中集装箱i的重量为wi。
//      要求轮船在装载体积不受限制的情况下装尽可能**多**的集装箱。
typedef struct {
    int index;
    int weight;
} Cargo;
bool comp(Cargo *c1, Cargo *c2) {
    return c1->weight < c2->weight;
}

/**
 * @param load 表示是否装入集装箱，1装0不装
 * @param x 记录装载的货物，0未装载，1装载
 * @param c 轮船载重
 * */
// 贪心 —— 最轻者先装
// O(nlogn)
void Loading(int weight[], int *x, int c, int len) {
    Cargo **cargo = (Cargo **) malloc(sizeof(Cargo*)*len);
    for (int i = 0; i < len; ++i) {
        cargo[i] = (Cargo *) malloc(sizeof(Cargo));
        cargo[i]->weight = weight[i];
        cargo[i]->index = i;
    }
    // 排序，谁轻装谁
    sort(cargo, cargo+len, comp);

    for (int i = 0; i < len && cargo[i]->weight <= c; ++ i) {
        c -= cargo[i]->weight;
        x[cargo[i]->index] = 1;
    }
}

int main() {
    int c = 10;
    int weight[] = {3, 5, 1, 2, 6};
    int len = sizeof(weight) / sizeof(weight[0]);
    int *x = new int[len];
    Loading(weight, x, c, len);
    for (int i = 0; i < len; ++ i) {
        printf("%d ", x[i]);
    }
}