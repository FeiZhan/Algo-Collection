//82A - Double Cola 
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

	long long num, two_cnt;
	while (cin >> num)
	{
		num --;
		two_cnt = 1;
		while (num - two_cnt * 5 >= 0)
		{
			num -= two_cnt * 5;
			two_cnt *= 2;
		}
		//cout << num << " " << two_cnt << endl;
		switch (num / two_cnt)
		{
		case 0:
			cout << "Sheldon" << endl;
			break;
		case 1:
			cout << "Leonard" << endl;
			break;
		case 2:
			cout << "Penny" << endl;
			break;
		case 3:
			cout << "Rajesh" << endl;
			break;
		case 4:
			cout << "Howard" << endl;
			break;
		default:
			cout << "other" << endl;
			break;
		}
	}

	return 0;
}