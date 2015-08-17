// partly WA
// scanf, printf to speed up

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
#include <climits>

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

	int data_num, sum;
	std::cin >> data_num >> sum;
	std::vector<int> data_list;
	int data, tmp_sum = 0, begin = 0, addition = INT_MAX / 2;
	for (int i = 0; i < data_num; ++ i)
	{
		//std::cin >> data;
		scanf("%d", &data);
		data_list.push_back(data);
		tmp_sum += data;
		if (tmp_sum < sum)
		{
			continue;
		}
		if (tmp_sum >= sum && tmp_sum - sum < addition)
		{
			addition = tmp_sum - sum;
		}
		while (begin < data_list.size() && tmp_sum - data_list[begin] >= sum && tmp_sum - data_list[begin] - sum <= addition)
		{
			tmp_sum -= data_list[begin];
			addition = tmp_sum - sum;
			++ begin;
		}
		while (begin < data_list.size() && tmp_sum > sum + addition)
		{
			tmp_sum -= data_list[begin];
			++ begin;
		}
//std::cout << "test " << begin + 1 << "-" << data_list.size() << " addition " << addition << std::endl;
		if (tmp_sum == sum + addition)
		{
			//std::cout << begin + 1 << "-" << data_list.size() << std::endl;
			printf("%d-%d\n", begin + 1, data_list.size());
		}
	}

	return 0;
}
