#include <string.h>

int numDecodings(char* s) {
    if (!s || s[0] == '0') {
        return 0;
    }

    int n = strlen(s);

    // dp[i] represents number of ways to decode substring s[0...i-1]
    // prev2 = dp[i-2], prev1 = dp[i-1]
    int prev2 = 1; // Empty string has 1 valid way
    int prev1 = 1; // First character (known != '0') has 1 valid way

    for (int i = 2; i <= n; i++) {
        int current = 0;

        // 1-digit decode: check s[i-1]
        if (s[i - 1] != '0') {
            current += prev1;
        }

        // 2-digit decode: check s[i-2...i-1]
        int two_digit = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (two_digit >= 10 && two_digit <= 26) {
            current += prev2;
        }

        // If at any point neither single nor double digit transition is valid
        if (current == 0) {
            return 0;
        }

        // Shift states forward
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}
