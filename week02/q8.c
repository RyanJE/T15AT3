int polynomialEval(int *a, int x, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = (sum + a[i])
        if (i < n-1) {
            sum *= x;
        }
    }
    return sum;
}

/*

4x^3 + 2x^2 + x + 1

(((4x + 2)x + 1)x + 1)

*/