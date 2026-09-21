#include <stdlib.h>
#include <string.h>

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void backtrack(int* nums, int numsSize, int start, int** result, int* count) {
    if (start == numsSize) {
        result[*count] = (int*)malloc(numsSize * sizeof(int));
        memcpy(result[*count], nums, numsSize * sizeof(int));
        (*count)++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        swap(&nums[start], &nums[i]);
        backtrack(nums, numsSize, start + 1, result, count);
        swap(&nums[start], &nums[i]); // backtrack
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1;
    for (int i = 2; i <= numsSize; i++) {
        total *= i;
    }

    *returnSize = total;

    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));

    for (int i = 0; i < total; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    int count = 0;
    backtrack(nums, numsSize, 0, result, &count);

    return result;
}
