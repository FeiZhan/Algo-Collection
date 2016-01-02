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

#include <string>
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

	string input;
	bool flag;
	while (cin >> input)
	{
		flag = true;
		for (string::size_type i = 1; i < input.size(); ++ i)
		{
			if (input.at(i) < 'A' || input.at(i) > 'Z')
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			for (string::size_type i = 0; i < input.size(); ++ i)
			{
				if (input.at(i) >= 'A' && input.at(i) <= 'Z')
				{
					input[i] = input.at(i) - 'A' + 'a';
				}
				else if (input.at(i) >= 'a' && input.at(i) <= 'z')
				{
					input[i] = input.at(i) - 'a' + 'A';
				}
			}
		}
		cout << input << endl;
	}
	return 0;
}
