void merge(int a[], int b[], int m, int n)
{
	// last location of array a
	int k = m + n - 1;
	// last element in array b
	int i = n - 1;
	// last element in array a
	int j = m - 1;
	while (i >= 0 && j >= 0)
	{
		if (a[i] > b[j])
		{
			a[k --] = a[i --];
		} else
		{
			a[k --] = b[j --];
		}
	}
	while (j >= 0)
	{
		a[k --] = b[j --];
	}
	// don't need to copy the rest of a
}
