int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    int left = 1;
    int right = x;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Use division to prevent 32-bit integer overflow (mid * mid > x)
        if (mid <= x / mid) {
            ans = mid;
            left = mid + 1; // Try to find a larger integer
        } else {
            right = mid - 1; // Search in the lower half
        }
    }

    return ans;
}
