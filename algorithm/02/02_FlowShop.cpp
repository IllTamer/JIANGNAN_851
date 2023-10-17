#include "../../main.h"

#include <iostream>
#include <algorithm>
using namespace std;

// 流水作业调度 —— Johnson不等式
// N个作业{1,2,...,n}要在由两台机器M1和M2组成的流水线上完成加工。
//      每个作业加工的顺序都是先在M1上加工，然后在M2上加工。M1和M2加工作业i
//      所需的时间分别为ai和bi，1≤i≤n。流水作业高度问题要求确定这n个作业的
//      最优加工顺序，使得从第一个作业在机器M1上开始加工，到最后一个作业在
//      机器M2上加工完成所需的时间最少。
// https://www.cnblogs.com/wkfvawl/p/11667092.html
// https://cloud.tencent.com/developer/article/2181393

// 流水作业调度问题的Johnson算法
// 1. 令 N1 = {i|ai<bi}, N2 = {i|ai>=bi}
// 2. 将N1中作业按ai升序，N2中作业按bi降序
// 3. N1中作业接N2中作业构成满足Johnson法则最优调度
// T(S,t)=ai+T(S-{i}, bi+max{t-ai, 0})=ai+aj+T(S-{i,j},tij)
// 其中 tij=bj+bi-aj-ai+max{t, ai+aj-bi, ai}

typedef struct {
    int a, b;
    int index; // 当前任务序号
} Job;

bool cmpN1(Job *job1, Job *job2) {
    return job1->a < job2->a;
}
bool cmpN2(Job *job1, Job *job2) {
    return job1->b > job2->b;
}

// 时间复杂度O(nlogn)，空间复杂度O(n)
int FlowShop(const int a[], const int b[], int n) {
    // 初始化 a、b分为N1、N2两组
    // N1 a>b升序, N2 b>a降序
    Job *N1[n], *N2[n];
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; ++ i) {
        Job *job = (Job *) malloc(sizeof(Job));
        job->a = a[i];
        job->b = b[i];
        job->index = i;
        if (a[i] <= b[i]) {
            N1[num1 ++] = job;
        } else {
            N2[num2 ++] = job;
        }
    }
    sort(N1, N1+num1, cmpN1);
    sort(N2, N2+num2, cmpN2);

    // c 为符合Johnson算法算法的任务序号数组
    int c[n];
    // 赋值，已排好序，顺序输入即可
    for (int i = 0; i < num1; ++ i) c[i] = N1[i]->index;
    for (int i = 0; i < num2; ++ i) c[i+num1] = N2[i]->index;

    // 当前加工时间，从a的角度看，所以遍历时要+=a
    int nowTime = a[c[0]];
    // 最小加工时间，从b的角度看，所以遍历时要+=b
    int minTime = nowTime + b[c[0]];
    // 从第二个任务开始
    for (int i = 1; i < n; ++ i) {
        // 更新当前加工时间
        nowTime += a[c[i]];
        // 选取二者中更大的那个为最小加工时间（哪边大说明另一边机器闲置）
        minTime = max(nowTime, minTime);
        // 更新最小加工时间（+=b
        minTime += b[c[i]];
    }
    return minTime;
}

// 此算法用cpp格式，便于排序
int main() {
    int a[] = {2, 4, 3, 6, 1};
    int b[] = {5, 2, 3, 1, 7};
    int n = sizeof(a)/sizeof(a[0]);
    int min = FlowShop(a, b, n);
    printf("Min time: %d", min);
}