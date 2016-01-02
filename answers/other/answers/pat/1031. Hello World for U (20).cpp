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
	while (cin >> input) {
		vector<vector<char> > ushape((input.size() + 2) / 3, vector<char> ((input.size() + 2) / 3 + (input.size() + 2) % 3, ' '));
		for (size_t i = 0; i < ushape.size(); ++ i) {
			ushape[i][0] = input[i];
			ushape[i][ushape[ushape.size() - 1 - i].size() - 1] = input[input.size() - 1 - i];
		}
		for (size_t i = 0; i < ushape[0].size(); ++ i) {
			ushape[ushape.size() - 1][i] = input[ushape.size() - 1 + i];
		}
		for (size_t i = 0; i < ushape.size(); ++ i) {
			for (size_t j = 0; j < ushape[i].size(); ++ j) {
				cout << ushape[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}


















