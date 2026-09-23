/**
 * Problem: LeetCode 32 - Longest Valid Parentheses
 * Language: C
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
#include <string.h>

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if (n <= 1) return 0;

    int left = 0, right = 0, max_len = 0;

    // Pass 1: Left to right
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            int current_len = 2 * right;
            if (current_len > max_len) {
                max_len = current_len;
            }
        } else if (right > left) {
            left = right = 0;
        }
    }

    left = right = 0;

    // Pass 2: Right to left
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            int current_len = 2 * left;
            if (current_len > max_len) {
                max_len = current_len;
            }
        } else if (left > right) {
            left = right = 0;
        }
    }

    return max_len;
}
