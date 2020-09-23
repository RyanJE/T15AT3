int binarySearchOrig(int A[], int n, int value) {
    int lo = 0;
    int hi = n -1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (A[mid] == value) {
            return mid;
        } else if (value < A[mid]) {
            hi = mid -1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;//cant find value
}

int binarySearch(int A[], int n, int value) {
    int lo = 0;
    int hi = n -1;
    return doBinarySearch(A, lo, hi, value);
    
}
int doBinarySearch(int A[], int lo, int hi, int value) {
        int mid = (lo + hi)/2;
        if (lo >= hi) {
            return -1;
        } else if (A[mid] == value) {
            return mid;
        } else if (value < A[mid]) {
            return doBinarySearch(A, lo, mid-1, value);
        } else {
            return doBinarySearch(A, mid + 1, hi, value);
        }
}