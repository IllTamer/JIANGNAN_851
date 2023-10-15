#include "../../main.h"

// 斐波那契数列 O(n)
// f(n) = f(n-1) + f(n-2), f(0) = f(1) = 1;
int Fibonacci(int n) {
    if (n <= 1) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

// 最大子段和（分治法
// TODO 这个用分治纯粹舍近求远了，推荐动态规划，分治法也不大可能考

int main() {
    printf("Fibonacci: %d", Fibonacci(6));
}