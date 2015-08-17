//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int max_level = 0;
void countLeaves(map<int, vector<int> > &tree, vector<size_t> &leaves, int current, int level)
{
	if (tree.find(current) == tree.end() || 0 == tree[current].size())
	{
		++leaves[level];
		if (level > max_level)
		{
			max_level = level;
		}
		return;
	}
	for (size_t i = 0; i < tree[current].size(); ++i)
	{
		countLeaves(tree, leaves, tree[current][i], level + 1);
	}
}
int main(int argc, char *argv[])
{
	map<int, vector<int> > tree;
	size_t node_num, nonleaf_num;
	cin >> node_num >> nonleaf_num;
	size_t child_num;
	int parent, child;
	for (size_t i = 0; i < nonleaf_num; ++i)
	{
		cin >> parent >> child_num;
		tree.insert(make_pair(parent, vector<int>()));
		for (size_t j = 0; j < child_num; ++j)
		{
			cin >> child;
			tree[parent].push_back(child);
		}
	}
	vector<size_t> leaves(node_num, 0);
	countLeaves(tree, leaves, 1, 0);
	for (size_t i = 0; i <= max_level; ++i)
	{
		if (i > 0)
		{
			cout << " ";
		}
		cout << leaves[i];
	}
	cout << endl;
	return 0;
}