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
#include <queue>

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

	int case_num;
	std::cin >> case_num;
	for (int i = 0; i < case_num; ++ i)
	{
		int row_num, column_num;
		std::cin >> row_num >> column_num;
		int entrx, entry, exitx, exity;
		std::cin >> entrx >> entry >> exitx >> exity;
		std::vector<std::vector<long long> > maze_mat;
		for (int j = 0; j < row_num; ++ j)
		{
			long long maze;
			std::vector<long long> maze_vec;
			for (int k = 0; k < column_num; ++ k)
			{
				std::cin >> maze;
				maze_vec.push_back(maze);
			}
			maze_mat.push_back(maze_vec);
		}
		bool flag = false;
		std::vector<std::vector<bool> > visit_mat(row_num, std::vector<bool>(column_num, false));
		std::vector<std::vector<int> > level_mat(row_num, std::vector<int>(column_num, -1));
		std::vector<std::vector<long long> > power_mat(row_num, std::vector<long long>(column_num, 0));
		std::vector<std::vector<int> > dir_mat(row_num, std::vector<int>(column_num, -1));
		const int Direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		std::queue<int> quex, quey;
		quex.push(entrx);
		quey.push(entry);
		level_mat[entrx][entry] = 0;
		power_mat[entrx][entry] = maze_mat[entrx][entry];
		int nowx = -1, nowy = -1, prevx = -1, prevy = -1;
		while (! quex.empty() && ! quey.empty())
		{
			nowx = quex.front();
			quex.pop();
			nowy = quey.front();
			quey.pop();
			if (nowx < 0 || nowx >= row_num || nowy < 0 || nowy >= column_num || visit_mat[nowx][nowy])
			{
				//std::cout << "debug out " << nowx << " " << nowy << std::endl;
				continue;
			}
			visit_mat[nowx][nowy] = true;
			//if (power_mat)
			if (maze_mat[nowx][nowy] < 0)
			{
				//std::cout << "debug trap " << nowx << " " << nowy << std::endl;
				continue;
			}
			if (nowx == exitx && nowy == exity)
			{
				//std::cout << "debug exit " << nowx << " " << nowy << std::endl;
				flag = true;
				break;
			}
			for (int j = 0; j < 4; ++ j)
			{
				int nextx = nowx + Direction[j][0];
				int nexty = nowy + Direction[j][1];
				if (nextx >= 0 && nextx < row_num && nexty >= 0 && nexty < column_num && ! visit_mat[nextx][nexty])
				{
					if (level_mat[nextx][nexty] > level_mat[nowx][nowy] + 1 || -1 == level_mat[nextx][nexty])
					{
						level_mat[nextx][nexty] = level_mat[nowx][nowy] + 1;
						power_mat[nextx][nexty] = power_mat[nowx][nowy] + maze_mat[nextx][nexty];
						dir_mat[nextx][nexty] = j;
						quex.push(nextx);
						quey.push(nexty);
					}
					else if (level_mat[nextx][nexty] == level_mat[nowx][nowy] + 1 && power_mat[nextx][nexty] < power_mat[nowx][nowy] + maze_mat[nextx][nexty])
					{
						level_mat[nextx][nexty] = level_mat[nowx][nowy] + 1;
						power_mat[nextx][nexty] = power_mat[nowx][nowy] + maze_mat[nextx][nexty];
						dir_mat[nextx][nexty] = j;
						quex.push(nextx);
						quey.push(nexty);
					}
				}
			}
			//std::cout << "debug now " << nowx << " " << nowy << " " << quex.size() << std::endl;
			prevx = nowx, prevy = nowy;
		}
		std::cout << "Case #" << i + 1 << ": " << std::flush;
		if (flag)
		{
			long long power = maze_mat[entrx][entry];
			int nowx = exitx, nowy = exity;
			while (nowx != entrx || nowy != entry)
			{
				power += maze_mat[nowx][nowy];
				int prevx = nowx - Direction[dir_mat[nowx][nowy]][0];
				int prevy = nowy - Direction[dir_mat[nowx][nowy]][1];
				//std::cout << "debug " << nowx << " " << nowy << " " << dir_mat[nowx][nowy] << " " << prevx << " " << prevy << std::endl;
				nowx = prevx;
				nowy = prevy;
			}
			std::cout << power << std::endl;
		} else
		{
			std::cout << "Mission Impossible." << std::endl;
		}
	}

	return 0;
}
