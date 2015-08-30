//
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <vector>
bool check(const std::vector<int> &preorder, std::vector<int> &postorder, int &mirror)
{
	if (preorder.size() == 0)
	{
		return true;
	}
/*
for (int i = 0; i < preorder.size(); ++ i)
{
	std::cout << preorder[i] << " ";
}
std::cout << std::endl;
*/
	int root = preorder[0], i;
	int tmp_mirror = mirror;
	for (i = 1; i < preorder.size(); ++ i)
	{
		if (0 == tmp_mirror)
		{
			tmp_mirror = preorder[i] > preorder[0] ? 1 : -1;
		}
		if ((1 == tmp_mirror && preorder[i] < preorder[0]) || (-1 == tmp_mirror && preorder[i] >= preorder[0]))
		{
			break;
		}
	}
//std::cout << "test " << root << " " << i << std::endl;
	for (int j = i; j < preorder.size(); ++ j)
	{
		if ((1 == tmp_mirror && preorder[j] >= preorder[0]) || (-1 == tmp_mirror && preorder[j] < preorder[0]))
		{
			return false;
		}
	}
	if (0 == mirror && (i > 1 || preorder.size() - 1 - i > 0))
	{
		mirror = tmp_mirror;
	}
	std::vector<int> pre0, pre1, post0, post1;
	pre0.insert(pre0.begin(), preorder.begin() + 1, preorder.begin() + i);
	pre1.insert(pre1.begin(), preorder.begin() + i, preorder.end());
	if (! check(pre0, post0, mirror) || ! check(pre1, post1, mirror))
	{
		return false;
	}
	postorder.insert(postorder.end(), post0.begin(), post0.end());
	postorder.insert(postorder.end(), post1.begin(), post1.end());
	postorder.insert(postorder.end(), root);
	return true;
}

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int node_num, node;
	std::cin >> node_num;
	std::vector<int> node_list;
	for (int i = 0; i < node_num; ++ i)
	{
		std::cin >> node;
		node_list.push_back(node);
	}
	std::vector<int> post_order;
	int mirror = 0;
	if (check(node_list, post_order, mirror))
	{
		std::cout << "YES" << std::endl;
		for (int i = 0; i < post_order.size(); ++ i)
		{
			if (0 < i)
			{
				std::cout << " ";
			}
			std::cout << post_order[i];
		}
		std::cout << endl;
	} else
	{
		std::cout << "NO" << std::endl;
	}

	return 0;
}
