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

	int column_num = 0;
	while (cin >> column_num && column_num) {
		string input_words;
		cin >> input_words;
		vector<vector<char> > words(input_words.length() / column_num, vector<char> (column_num, '\0'));
		bool direction = false;
		for (size_t i = 0; i < input_words.length(); ++ i) {
			if (0 == i % column_num) {
				direction = ! direction;
			}
			words[i / column_num][direction ? (i % column_num) : (column_num - 1 - i % column_num)] = input_words[i];
		}
		for (size_t i = 0; i < words[0].size(); ++ i) {
			for (size_t j = 0; j < words.size(); ++ j) {
				cout << words[j][i];
			}
			//cout << endl;
		}
		cout << endl;
	}

	return 0;
}


















