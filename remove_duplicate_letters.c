/**
 * Problem: LeetCode 316 - Remove Duplicate Letters
 * Language: C
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* removeDuplicateLetters(char* s) {
    int last_index[26] = {0};
    bool in_stack[26] = {false};
    int len = strlen(s);

    // Record the last occurrence of each character
    for (int i = 0; i < len; i++) {
        last_index[s[i] - 'a'] = i;
    }

    // Stack to build the result string (max 26 letters + null terminator)
    char* stack = (char*)malloc(27 * sizeof(char));
    int top = 0;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        int idx = c - 'a';

        // If the character is already in our result, skip it
        if (in_stack[idx]) {
            continue;
        }

        // Monotonic stack logic:
        // Pop characters that are:
        // 1. Greater than the current character 'c' (to keep lexicographical order)
        // 2. Will appear again later in the string (i < last_index of that character)
        while (top > 0 && stack[top - 1] > c && last_index[stack[top - 1] - 'a'] > i) {
            in_stack[stack[top - 1] - 'a'] = false;
            top--;
        }

        // Push current character
        stack[top++] = c;
        in_stack[idx] = true;
    }

    stack[top] = '\0';
    return stack;
}
