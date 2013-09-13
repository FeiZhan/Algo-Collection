//Problem A. Speaking in Tongues
//#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../A-small-attempt0.in");
	cin.rdbuf(fin.rdbuf()); // assign file's streambuf to cin
#ifdef _C_LAN_
	freopen("../A-small-attempt0.in", "r", stdin);
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

	int case_sum;
	string str;
	const string CONVERT("yhesocvxduiglbkrztnwjpfmaq");
	cin >> case_sum;
	getline(cin, str);
	for (size_t i = 1; i <= case_sum; ++ i)
	{
		getline(cin, str);
		for (size_t j = 0; j < str.size(); ++ j)
		{
			if (str.at(j) >= 'a' && str.at(j) <= 'z')
			{
				str[j] = CONVERT.at(str.at(j) - 'a');
			}
		}
		cout << "Case #" << i << ": " << str << endl;
	}

	return 0;
}