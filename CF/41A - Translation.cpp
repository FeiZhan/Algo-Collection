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
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	//cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	std::string word1, word2;
	cin >> word1 >> word2;
	if (word1.length() != word2.length())
	{
		std::cout << "NO" << std::endl;
	} else
	{
		bool flag = true;
		for (size_t i = 0; i < word1.length(); ++ i)
		{
			if (word1[i] != word2[word2.length() - 1 - i])
			{
				flag = false;
				break;
			}
		}
		std::cout << ( flag ? "YES" : "NO" ) << std::endl;
	}

	return 0;
}
