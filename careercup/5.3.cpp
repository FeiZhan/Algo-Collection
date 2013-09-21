int getNextNP(int n)
{
	if (n <= 0)
	{
		return -1;
	}
	int index = 0;
	int count_ones = 0;
	// find first one
	while (! getBit(n, index))
	{
		++ index;
	}
	// turn on next zero
	while (getBit(n, index))
	{
		++ index;
		++ count_ones;
	}
	setBit(n, index, true);
	// turn off previous one
	-- index;
	setBit(n, index, false);
	-- count_ones;
	// set zeros
	for (int i = index - 1; i >= count_ones; -- i)
	{
		setBit(n, i, false);
	}
	// set ones
	for (int i = count_ones - 1; i >= 0; -- i)
	{
		setBit(n, i, true);
	}
	return n;
}
int getPreviousNP(int n)
{
	if (n <= 0)
	{
		return -1;
	}
	int index = 0;
	int count_zeros = 0;
	// find first zero
	while (getBit(n, index))
	{
		++ index;
	}
	// turn off next 1
	while (! getBit(n, index))
	{
		++ index;
		++ count_zeros;
	}
	setBit(n, index, false);
	// turn on previous zero
	-- index;
	setBit(n, index, true);
	-- count_zeros;
	// set ones
	for (int i = index - 1; i >= count_zeros; -- i)
	{
		setBit(n, i, true);
	}
	// set zeros
	for (int i = count_zeros - 1; i >= 0; -- i)
	{
		setBit(n, i, false);
	}
	return n;
}
bool getBit(int n, int index)
{
	return (n & (1 << index)) > 0;
}
void setBit(int &n, int index, bool b)
{
	if (b)
	{
		n = n | (1 << index);
	} else
	{
		n = n & (~ (1 << index));
	}
}
