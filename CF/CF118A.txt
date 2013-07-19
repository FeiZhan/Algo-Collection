//118A - String Task 
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

	string word;
	while (cin >> word)
	{
		for (int i = 0; i < word.size(); ++ i)
		{
			if (word.at(i) >= 'A' && word.at(i) <= 'Z')
			{
				word[i] += 'a' - 'A';
			}
			if (word.at(i) == 'a' || word.at(i) == 'e' || word.at(i) == 'i'
				|| word.at(i) == 'o' || word.at(i) == 'u' || word.at(i) == 'y')
			{
				word.erase(i, 1);
				-- i;
			}
			else
			{
				word.insert(i, ".");
				++ i;
			}
		}
		cout << word << endl;
	}

	return 0;
}