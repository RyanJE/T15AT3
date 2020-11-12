void shellSort(int a[], int lo, int hi)
{
	int i, j, h, val;
	for (h = 1; h <= (hi - lo) / 9; h = 3 * h + 1) ;
	for ( ; h > 0; h /= 3) {
		for (i = lo + h; i <= hi; i++) {
			j = i;
			val = a[i];
			while (j >= lo + h && val < a[j - h]) {
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = val;
		}
	}
}