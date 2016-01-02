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

#include <stack>

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

	int capacity, data_num, seq_num, seq, head;
	std::cin >> capacity >> data_num >> seq_num;
	bool flag;
	std::stack<int> q;
	for (int i = 0; i < seq_num; ++ i)
	{
		while (! q.empty())
		{
			q.pop();
		}
		head = 1;
		flag = true;
		for (int j = 0; j < data_num; ++ j)
		{
			std::cin >> seq;
			if (! flag)
			{
				continue;
			}
			for (; head <= seq; ++ head)
			{
				q.push(head);
			}
			if (q.top() != seq || q.size() > capacity)
			{
				flag = false;
				continue;
			}
			q.pop();
		}
		std::cout << (flag ? "YES" : "NO") << std::endl;
	}

	return 0;
}
