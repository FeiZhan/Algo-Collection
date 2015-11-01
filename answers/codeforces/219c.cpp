//219C - Color Stripe
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <memory.h>
char color[510000];
int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("./input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("./input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("./output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("./output.txt", "w", stdout);
#endif
#endif

	int cell_num, color_num, repaint_cnt, tmp;
	bool is_a;
	while (cin >> cell_num >> color_num)
	{
		for (int i = 0; i < cell_num; ++ i)
		{
			cin >> color[i];
		}
		color[cell_num] = 0;
		repaint_cnt = 0;
		if (color_num == 2)
		{
			is_a = true;
			for (int i = 0; i < cell_num; ++ i)
			{
				if (is_a && color[i] == 'A')
				{
					++ repaint_cnt;
				}
				else if (! is_a && color[i] == 'B')
				{
					++ repaint_cnt;
				}
				is_a = ! is_a;
			}
			is_a = false;
			tmp = 0;
			for (int i = 0; i < cell_num; ++ i)
			{
				if (is_a && color[i] == 'A')
				{
					++ tmp;
				}
				else if (! is_a && color[i] == 'B')
				{
					++ tmp;
				}
				is_a = ! is_a;
			}
			if (tmp <= repaint_cnt)
			{
				repaint_cnt = tmp;
				is_a = false;
			} else
			{
				is_a = true;
			}
			for (int i = 0; i < cell_num; ++ i)
			{
				color[i] = is_a ? 'B' : 'A';
				is_a = ! is_a;
			}
		} else
		{
			for (int i = 1; i < cell_num - 1; ++ i)
			{
				if (color[i] == color[i - 1])
				{
					repaint_cnt ++;
					for (int j = 0; j < color_num; ++ j)
					{
						if (static_cast<char>(j+'A') != color[i - 1]
							&& static_cast<char>(j+'A') != color[i + 1])
						{
							color[i] = static_cast<char>(j+'A');
							break;
						}
					}
				}
			}
			if (color[cell_num - 1] == color[cell_num - 2])
			{
				repaint_cnt ++;
				if (color[cell_num - 2] == 'A')
				{
					color[cell_num - 1] = 'B';
				} else
				{
					color[cell_num - 1] = 'A';
				}
			}
		}
		cout << repaint_cnt << endl << color << endl;
	}

	return 0;
}

