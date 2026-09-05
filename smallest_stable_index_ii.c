#include <stdlib.h>

int firstStableIndex(int* nums, int numsSize, int k) {
    int* suffMin = (int*)malloc(sizeof(int) * numsSize);
    if (!suffMin) return -1;

    suffMin[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        suffMin[i] = (nums[i] < suffMin[i + 1]) ? nums[i] : suffMin[i + 1];
    }

    int prefMax = nums[0];
    int ans = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > prefMax) {
            prefMax = nums[i];
        }
        if ((long long)prefMax - suffMin[i] <= k) {
            ans = i;
            break;
        }
    }

    free(suffMin);
    return ans;
}
