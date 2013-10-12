int search(const int a[] const, size_t len, int x)
{
	int l = 0;
	int r = len - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (x == a[mid])
		{
			return mid;
		} else if (a[l] <= a[mid])
		{
			if (x > a[m])
			{
				l = m + 1;
			} else if (x >= a[l])
			{
				r = mid - 1;
			} else
			{
				l = m + 1;
			}
		}
		else if (x < a[m])
		{
			r = m - 1;
		}
		else if (x <= a[u])
		{
			l = m + 1;
		} else
		{
			r = m - 1;
		}
	}
	return -1;
}
