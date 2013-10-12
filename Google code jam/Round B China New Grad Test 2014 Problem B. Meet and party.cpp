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

#include <cmath>
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

	int case_num;
	std::cin >> case_num;
	for (int i = 0; i < case_num; ++ i)
	{
		int square_num;
		std::cin >> square_num;
		std::vector<int> c1x_vec, c1y_vec, c2x_vec, c2y_vec;
		double centerx = 0.0, centery = 0.0;
		for (int j = 0; j < square_num; ++ j)
		{
			int corner1x, corner1y, corner2x, corner2y;
			std::cin >> corner1x >> corner1y >> corner2x >> corner2y;
			centerx += corner1x * 2 + corner2x * 2;
			centery += corner1y * 2 + corner2y * 2;
			c1x_vec.push_back(corner1x);
			c1y_vec.push_back(corner1y);
			c2x_vec.push_back(corner2x);
			c2y_vec.push_back(corner2y);
		}
		centerx /= square_num * 4.0;
		centery /= square_num * 4.0;
		int targetx = INT_MAX, targety = INT_MAX, min_dist = INT_MAX;
		int target_num = INT_MAX;
		for (int j = 0; j < square_num; ++ j)
		{
			if (c1x_vec[j] <= centerx && centerx <= c2x_vec[j] && c1y_vec[j] <= centery && centery <= c2y_vec[j])
			{
				targetx = int(centerx + 0.499999);
				targety = int(centery + 0.499999);
				target_num = INT_MAX;
				break;
			} else
			{
				int dist = 0;
				dist = abs(centerx - c1x_vec[j]) + abs(centery - c1y_vec[j]);
				if (min_dist > dist || (min_dist == dist && targetx > c1x_vec[j]) || (min_dist == dist && targetx == c1x_vec[j] && targety > c1y_vec[j]))
				{
					min_dist = dist;
					targetx = c1x_vec[j];
					targety = c1y_vec[j];
					target_num = j;
				}
				dist = abs(centerx - c2x_vec[j]) + abs(centery - c1y_vec[j]);
				if (min_dist > dist || (min_dist == dist && targetx > c2x_vec[j]) || (min_dist == dist && targetx == c2x_vec[j] && targety > c1y_vec[j]))
				{
					min_dist = dist;
					targetx = c2x_vec[j];
					targety = c1y_vec[j];
					target_num = j;
				}
				dist = abs(centerx - c1x_vec[j]) + abs(centery - c2y_vec[j]);
				if (min_dist > dist || (min_dist == dist && targetx > c1x_vec[j]) || (min_dist == dist && targetx == c1x_vec[j] && targety > c2y_vec[j]))
				{
					min_dist = dist;
					targetx = c1x_vec[j];
					targety = c2y_vec[j];
					target_num = j;
				}
				dist = abs(centerx - c2x_vec[j]) + abs(centery - c2y_vec[j]);
				if (min_dist > dist || (min_dist == dist && targetx > c2x_vec[j]) || (min_dist == dist && targetx == c2x_vec[j] && targety > c2y_vec[j]))
				{
					min_dist = dist;
					targetx = c2x_vec[j];
					targety = c2y_vec[j];
					target_num = j;
				}
			}
		}
		if (target_num < INT_MAX)
		{
			if (c1x_vec[target_num] <= centerx && centerx <= c2x_vec[target_num])
			{
				targetx = centerx;
			}
			if (c1y_vec[target_num] <= centery && centery <= c2y_vec[target_num])
			{
				targety = centery;
			}
		}
		min_dist = 0;
		for (int j = 0; j < square_num; ++ j)
		{
			for (int m = c1x_vec[j]; m <= c2x_vec[j]; ++ m)
			{
				for (int n = c1y_vec[j]; n <= c2y_vec[j]; ++ n)
				{
					min_dist += abs(targetx - m) + abs(targety - n);
				}
			}
		}
		std::cout << "Case #" << i + 1 << ": " << targetx << " " << targety << " " << min_dist << std::endl;
	}

	return 0;
}
