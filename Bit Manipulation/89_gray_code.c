int* grayCode(int n, int* returnSize) {
    int total = 1 << n;
    *returnSize = total;
    int* result = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) {
        result[i] = i ^ (i >> 1);
    }
    return result;
}
