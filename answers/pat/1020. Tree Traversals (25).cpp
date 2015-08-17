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
#include <algorithm>
#include <deque>
struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int v = 0) : val(v), left(NULL), right(NULL)
	{}
	void levelTraverse()
	{
		std::deque<TreeNode *> traverse;
		traverse.push_back(this);
		bool flag = false;
		while (! traverse.empty())
		{
			TreeNode *now = traverse.front();
			traverse.pop_front();
			if (NULL == now || now->val <= 0)
			{
				continue;
			}
			if (flag)
			{
				std::cout << " ";
			} else
			{
				flag = true;
			}
			std::cout << now->val;
			traverse.push_back(now->left);
			traverse.push_back(now->right);
		}
	}
};
void parse(const std::vector<int> &post, std::vector<int> &in, TreeNode *root)
{
	if (0 == post.size())
	{
		return;
	}
	if (NULL == root)
	{
		root = new TreeNode;
	}
	root->val = post[post.size() - 1];
	std::vector<int>::iterator root_it = std::find(in.begin(), in.end(), root->val);
	if (in.end() == root_it)
	{
		return;
	}
	std::vector<int> left_in(in.begin(), root_it), left_post(post.begin(), post.begin() + left_in.size());
	root->left = new TreeNode;
	parse(left_post, left_in, root->left);
	std::vector<int> right_in(root_it + 1, in.end()), right_post(post.begin() + left_in.size(), post.end() - 1);
	root->right = new TreeNode;
	parse(right_post, right_in, root->right);
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

	int node_num, tmp;
	std::cin >> node_num;
	std::vector<int> post, in;
	for (int i = 0; i < node_num; ++ i)
	{
		std::cin >> tmp;
		post.push_back(tmp);
	}
	for (int i = 0; i < node_num; ++ i)
	{
		std::cin >> tmp;
		in.push_back(tmp);
	}
	TreeNode *root = new TreeNode;
	parse(post, in, root);
	root->levelTraverse();
	return 0;
}
