#include <stdlib.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // Array to track elements present in nums1 (values range from 0 to 1000)
    bool present[1001] = {false};
    
    for (int i = 0; i < nums1Size; i++) {
        present[nums1[i]] = true;
    }
    
    int maxSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int* result = (int*)malloc(sizeof(int) * maxSize);
    int count = 0;
    
    for (int i = 0; i < nums2Size; i++) {
        if (present[nums2[i]]) {
            result[count++] = nums2[i];
            // Set to false to avoid adding duplicate entries to the result
            present[nums2[i]] = false; 
        }
    }
    
    *returnSize = count;
    return result;
}