
#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;       // Pointer for the last valid element in nums1
    int p2 = n - 1;       // Pointer for the last element in nums2
    int p = m + n - 1;    // Pointer for the last position of nums1

    // Traverse from the back and place the larger element at index p
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    // Copy any remaining elements from nums2 into nums1
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}