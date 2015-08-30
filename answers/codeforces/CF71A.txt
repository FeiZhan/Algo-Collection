//71A - Way Too Long Words 
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

	int case_sum;
	string word;
	cin >> case_sum;
	while (case_sum --)
	{
		cin >> word;
		if (word.size() > 10)
		{
			cout << word.at(0) << word.size() - 2 << word.at(word.size() - 1)
				<< endl;
		}
		else
		{
			cout << word << endl;
		}
	}

	return 0;
}