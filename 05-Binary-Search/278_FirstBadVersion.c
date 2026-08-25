// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2; // Prevents 32-bit integer overflow
        
        if (isBadVersion(mid)) {
            right = mid; // First bad version is at mid or earlier
        } else {
            left = mid + 1;    // Bad version must be after mid
        }
    }
    
    return left;
}
