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

#include <string>
#include <map>
struct Node
{
	std::string add;
	int value;
	std::string next;
	Node(const std::string &a, int v, const std::string &n) : add(a), value(v), next(n)
	{}
};

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

	int node_num;
	std::string head;
	std::cin >> node_num >> head;
	std::map<std::string, Node> list_map;
	for (int i = 0; i < node_num; ++ i)
	{
		char tmp1[10], tmp2[10];
		std::string add, next;
		int key;
		//std::cin >> add >> key >> next;
		scanf("%s %d %s", tmp1, &key, tmp2);
		add = tmp1;
		next = tmp2;
		Node n(add, key, next);
		list_map.insert(std::make_pair(add, n));
	}
	std::map<int, Node> value_map;
	while (true)
	{
		std::map<std::string, Node>::iterator find_it = list_map.find(head);
		if (list_map.end() == find_it || "-1" == head)
		{
			break;
		}
		value_map.insert(std::make_pair(find_it->second.value, find_it->second));
		head = find_it->second.next;
	}
	std::cout << value_map.size() << " " << (value_map.size() ? value_map.begin()->second.add : "-1") << std::endl;
	for (std::map<int, Node>::iterator it = value_map.begin(); it != value_map.end(); ++ it)
	{
		if (it != value_map.begin())
		{
			std::cout << it->second.add << std::endl;
		}
		std::cout << it->second.add << " " << it->first << " ";
	}
	if (value_map.size())
	{
		std::cout << -1 << std::endl;
	}

	return 0;
}
