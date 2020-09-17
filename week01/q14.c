// Pre:
// - a[] is a valid pointer to the start of an array of ints
// - n is a positive int indicating how many elements in a[]
// Post:
// - return value = ∀ i ∈ {0..n-2} ( a[i] ≤ a[i+1] )
bool isSorted(int *a, int n)
{
    int i = 0;
    while(i < n - 1) {
        if (a[i] > a[i+1]) {
            return false;
        }
        ++i;
    }
    return true;
    /*
    a[i] <= a[i+1]
    go through the list:
        check whether each pair follows property
    if not:
        not sorted
    else:
        is sorted
    */
}