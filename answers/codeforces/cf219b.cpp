//219B	 Special Offer! Super Price 999 Bourles!
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

	long long init, reduct, tmp, tmp2;
	int size;
	while (cin >> init >> reduct)
	{
		reduct = init - reduct;
		tmp = init;
		size = 0;
		while (tmp > 0)
		{
			++ size;
			tmp /= 10;
		}
		//cout << "size " << size << endl;
		for (int i = size; i >= 0; -- i)
		{
			tmp = 0;
			tmp2 = 1;
			for (int j = 0; j < i; ++ j)
			{
				tmp = tmp * 10 + 9;
				tmp2 *= 10;
			}
			//cout << "tmp2 " << tmp2 << endl;
			tmp += reduct / tmp2 * tmp2;
			//cout << "tmp " << tmp << endl;
			if (tmp >= reduct && tmp <= init)
			{
				while (tmp <= init)
				{
					tmp += tmp2;
				}
				cout << tmp - tmp2 << endl;
				break;
			}
		}
	}

	return 0;
}

