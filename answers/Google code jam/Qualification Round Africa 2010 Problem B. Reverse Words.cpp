// AC for small and large
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
#include <vector>

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
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int case_num;
	std::cin >> case_num;
	size_t delimiter;
	std::string line, word;
	std::vector<std::string> word_list;
	std::getline(std::cin, line);
	for (int i = 0; i < case_num; ++ i)
	{
		word_list.clear();
		std::getline(std::cin, line);
		while ((delimiter = line.find(' ')) != std::string::npos)
		{
			word = line.substr(0, delimiter);
			word_list.push_back(word);
			line.erase(0, delimiter + 1);
		}
		if (line.length() > 0)
		{
			word_list.push_back(line);
		}
		std::cout << "Case #" << i + 1 << ":";
		for (int i = word_list.size() - 1; i >= 0; -- i)
		{
			std::cout << " " << word_list[i];
		}
		std::cout << std::endl;
	}

	return 0;
}
