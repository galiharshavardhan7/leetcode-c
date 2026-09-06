#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    
    // An odd length string can never be balanced
    if (len % 2 != 0) {
        return false;
    }
    
    // Stack to store expected closing brackets
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        // Push the corresponding closing bracket
        if (c == '(') {
            stack[++top] = ')';
        } else if (c == '{') {
            stack[++top] = '}';
        } else if (c == '[') {
            stack[++top] = ']';
        } else {
            // If stack is empty or bracket doesn't match the top
            if (top == -1 || stack[top] != c) {
                return false;
            }
            top--; // Pop
        }
    }
    
    // Valid only if all opened brackets were matched
    return top == -1;
}
