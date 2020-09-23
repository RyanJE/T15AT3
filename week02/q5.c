// computes x^n
int powIterative(int x, unsigned int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * x;
    }
    return res;
}

/*
O(logn)
Recursive solution:
Base case:
n == 0: return 1
n == 1: return x
Recursive:
n%2 == 0: return pow(x*x, n/2)
n%2 == 1: return x*pow(x*x,n/2)

Even case:
2^8 --> 4^4 
9^4 --> 81^2

Odd case
2^9 --> 2*(2^8)
*/

int powRec(int x, unsigned int n) {
    if (n == 0) {
        return 1;
    } else if (n == 0) {
        return x;
    } else if (n %2 == 0) {
        return powRec(x*x, n/2);
    } else {
        return x*powRec(x*x, n/2);
    }
}
