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
#include <vector>
#include <algorithm>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("output.txt", "w", stdout);
#endif
#endif

	string input;
	getline(cin, input);
	vector<vector<bool> > dp(input.length(), vector<bool> (input.length(), false));
	size_t length_max = 0;
	for (size_t i = 0; i < input.length(); ++ i) {
		for (size_t j = 0; i + j < input.length(); ++ j) {
			if (0 == i || (1 == i && input[j] == input[j + i]) || (i >= 2 && dp[j + 1][i + j - 1] && input[j] == input[i + j])) {
				dp[j][i + j] = true;
				length_max = std::max(length_max, i + 1);
			}
		}
	}
	cout << length_max << endl;

	return 0;
}




