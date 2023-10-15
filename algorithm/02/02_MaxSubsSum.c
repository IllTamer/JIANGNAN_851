#include "../../main.h"

// 最大子段和
// O(n)
// b[j] = max{b[j-1]+a[j], a[j]} (1<=j<=n)
int MaxSubSum(const int nums[], int len) {
    int max = 0, sum = 0;
    for (int i = 0; i < len; ++ i) {
        // sum一直加到负值，后重置为当前数据
        sum = sum > 0 ? sum + nums[i] : nums[i];
        // 每次算完sum后更新记录值
        if (sum > max)
            max = sum;
    }
    return max;
}

int main() {
    int nums[] = {1, 2, -8, 5, -1, 6, 10};
    int max = MaxSubSum(nums, sizeof(nums)/sizeof(nums[0]));
    printf("MAx: %d", max);
}