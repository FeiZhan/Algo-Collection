// PE
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

	int case_num(0);
	cin >> case_num;
	while (case_num --) {
		int turtle_num(0);
		cin >> turtle_num;
		vector<string> turtle_list;
		cin.ignore();
		for (int i = 0; i < turtle_num; ++ i) {
			string name;
			getline(cin, name);
			turtle_list.push_back(name);
		}
		vector<string> target_list;
		for (int i = 0; i < turtle_num; ++ i) {
			string name;
			getline(cin, name);
			target_list.push_back(name);
		}
		size_t j = target_list.size() - 1;
		for (size_t i = turtle_list.size() - 1; i < turtle_list.size() && j < target_list.size(); -- i) {
			if (target_list[j] == turtle_list[i]) {
				-- j;
			}
		}
		for (size_t i = j; i < target_list.size(); -- i) {
			//cout << target_list[i] << endl;
			puts(target_list[i].c_str());
		}
		if (case_num) {
			printf("\n");
		}
	}

	return 0;
}













