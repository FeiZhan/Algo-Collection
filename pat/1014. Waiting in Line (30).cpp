// copied from http://blog.csdn.net/cloudbye/article/details/7792140
/*思路：由于等待队列已经确定，那么等待队列中的客户接受服务的窗口随之确定。根据这个思路，完全无视黄线的存在，把所有客户都插入到应该排队的队列，这样就可以计算出每个客户的接受服务时间和结束服务时间。
步骤：
先把n * m个客户拍到黄线内。
对剩下的客户，从等待顺序开始，为客户C找到正在服务的客户最早退出队列的窗口W。
把客户插入到窗口W，并更新窗口W的黄线内最后一个客户结束服务时间（Windows.fFime），正在服务客户。
更新客户C的开始服务时间和结束服务时间。
最后计算要求查询的客户的开始服务时间。
*/
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <queue>
#include <climits>
struct Customer
{
	int pTime, sTime, fTime;
};
struct Window
{
	int fTime;
	// queue for all the people in a window
	std::queue<int> q;
};
Customer cus[1005];
Window wins[25];
const int SEVENTEEN = 17 * 60;
const int EIGHT = 8 * 60;

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

	// int n, m, k, q;
	int win_num, max_cap, cus_num, que_num;
	std::cin >> win_num >> max_cap >> cus_num >> que_num;
	for (int i = 0; i < cus_num; ++ i)
	{
		std::cin >> cus[i].pTime;
	}
	int i, j;
	// enqueue the first win_num * max_cap customers
	for (i = 0, j = 0; i < win_num * max_cap && i < cus_num; ++ i)
	{
		cus[i].sTime = wins[j].fTime;
		cus[i].fTime = wins[j].fTime + cus[i].pTime;
		wins[j].fTime += cus[i].pTime;
		wins[j].q.push(i);
		// rotate within each window
		j = (j + 1) % win_num;
	}
	int mTime, pos, fro;
	// for the rest customers
	for (; i < cus_num; ++ i)
	{
		mTime = INT_MAX;
		// find the first finishing customer's window
		for (int j = 0; j < win_num; ++ j)
		{
			fro = wins[j].q.front();
			if (cus[fro].fTime < mTime)
			{
				mTime = cus[fro].fTime;
				pos = j;
			}
		}
		cus[i].sTime = wins[pos].fTime;
		cus[i].fTime = wins[pos].fTime + cus[i].pTime;
		wins[pos].fTime += cus[i].pTime;
		wins[pos].q.push(i);
		wins[pos].q.pop();
	}
	int que, hour, min;
	while (que_num --)
	{
		std::cin >> que;
		-- que;
		if (cus[que].sTime + EIGHT >= SEVENTEEN)
		{
			std::cout << "Sorry" << std::endl;
		} else
		{
			hour = (cus[que].fTime + EIGHT) / 60;
			min = (cus[que].fTime + EIGHT) % 60;
			if (hour < 10)
			{
				std::cout << "0";
			}
			std::cout << hour << ":";
			if (min < 10)
			{
				std::cout << "0";
			}
			std::cout << min << std::endl;
		}
	}

	return 0;
}
