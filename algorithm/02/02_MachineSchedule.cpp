#include "../../main.h"
#include <algorithm>
using namespace std;

// 多机调度问题
//      设有n个独立的作业，由m台相同的及其进行加工处理。作业i所需的处理时间为ti。
//      现要求给出一种方案，使所给的n个作业在尽可能短的时间内由m台机器加工处理完成。

// 贪心 —— 最长时间作业优先
// - 当n<=m时，依次分配即可 O(1)
// - 当n>m时，将作业降序排序，按顺序分配给空闲机器既可 O(nlogn)

typedef struct {
    int time; // 加工花费的时间
    int id;   // 加工的机器id
} Work;
bool comp(Work w1, Work w2) {
    return w1.time > w2.time;
}

// @return 加工总时间
int MachineSchedule(Work works[], int m, int n) {
    int time = 0;
    // 作业数 <= 机器数，加工时间为最长的那一项作业
    if (n <= m) {
        for (int i = 0; i < n; ++ i)
            time = max(time, works[i].time);
        return time;
    }
    sort(works, works+n, comp);

// 初始化最小堆
// MinHeap<int> heap; for i in range(0, m):
//      works[i]->id = i; // 记录机器序号
//      heap.insert(works[i]);

// 遍历剩余的任务
// for i in range(m, n):
//      machineWork = heap.pop();
//      machineWork->time += works[i]->time // 将任务分配到最先完成的机器
//      heap.push(machineWork); // 重新调整最小堆

// works[0, m]中最长加工时间即为总加工时间
}

int main() {}