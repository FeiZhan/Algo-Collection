std::vector<std::vector<int> > getSubsets(std::vector<int> set, int index)
{
	std::vector<std::vector<int> > all;
	if (set.size() > index)
	{
		all = getSubsets(set, index + 1);
		int item = set[index];
		std::vector<std::vector<int> > more;
		for (std::vector<std::vector<int> >::iterator it = all.begin(); it != all.end(); ++ it)
		{
			std::vector<int> new_subset(*it);
			new_subset.insert(new_subset.begin(), item);
			more.push_back(new_subset);
		}
		for (std::vector<std::vector<int> >::iterator it = more.begin(); it != more.end(); ++ it)
		{
			all.push_back(*it);
		}
	} else
	{
		// empty one
		all.push_back(std::vector<int>());
	}
	return all;
}
// Combinatorics
std::vector<std::vector<int> > getSubsets2(std::vector<int> set)
{
	std::vector<std::vector<int> > all;
	int max = 1 << set.size();
	for (int i = 0; i < max; ++ i)
	{
		std::vector<int> subset;
		int k = i;
		int index = 0;
		while (k > 0)
		{
			// check if k-th is needed
			if ((k & 1) > 0)
			{
				subset.add(set[index]);
			}
			k >>= 1;
			++ index;
		}
		all.push_back(subset);
	}
	return all;
}
