#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
        char* zero = (char*)malloc(2 * sizeof(char));
        strcpy(zero, "0");
        return zero;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int total_len = len1 + len2;

    int* product = (int*)calloc(total_len, sizeof(int));
    if (!product) return NULL;

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + product[i + j + 1];

            product[i + j + 1] = sum % 10;
            product[i + j] += sum / 10;
        }
    }

    int start = 0;
    while (start < total_len && product[start] == 0) {
        start++;
    }

    int result_len = total_len - start;
    char* result = (char*)malloc((result_len + 1) * sizeof(char));

    for (int i = 0; i < result_len; i++) {
        result[i] = product[start + i] + '0';
    }
    result[result_len] = '\0';

    free(product);
    return result;
}
