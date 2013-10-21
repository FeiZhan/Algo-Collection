//79A - Bus Game
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

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

	int hundred, ten;
	bool ciel_turn;
	while (cin >> hundred >> ten)
	{
		ciel_turn = false;
		while (true)
		{
			ciel_turn = ! ciel_turn;
			if (ciel_turn)
			{
				if (hundred >= 2 && ten >= 2)
				{
					hundred -= 2;
					ten -= 2;
				}
				else if (hundred >= 1 && ten >= 12)
				{
					hundred -= 1;
					ten -= 12;
				}
				else if (ten >= 22)
				{
					ten -= 22;
				} else
				{
					cout << "Hanako" << endl;
					break;
				}
			} else
			{
				if (ten >= 22)
				{
					ten -= 22;
				}
				else if (hundred >= 1 && ten >= 12)
				{
					hundred -= 1;
					ten -= 12;
				}
				else if (hundred >= 2 && ten >= 2)
				{
					hundred -= 2;
					ten -= 2;
				} else
				{
					cout << "Ciel" << endl;
					break;
				}
			}
		}
	}

	return 0;
}

