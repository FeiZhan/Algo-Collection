//A. Next Round
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
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf()); // assign file's streambuf to cin
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf()); // assign file's streambuf to cout
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int parti_sum, adv_num, parti, cnt;
	int adv_score;
	bool is_positive;
	while (cin >> parti_sum >> adv_num)
	{
		is_positive = true;
		cnt = 0;
		for (int i = 0; i < parti_sum; ++ i)
		{
			cin >> parti;
			if (cnt < adv_num && parti > 0)
			{
				cnt ++;
				adv_score = parti;
			}
			else if (parti == adv_score && parti > 0)
			{
				cnt ++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}