// O(2^n)
int fib(int n) {
    assert(n > 0);
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

/*
We want an iterative solution

O(n) complexity
*/
int fibN(int n) {
    int a = 1;
    int b = 1;
    int c = 2;
    if (n == 1 || n == 2) {
        return 1;
    } else {
        for (int count = 3; count <= n; count++) {
            a = b;
            b = c;
            c = b + a;
        }
        return c;
    }
}