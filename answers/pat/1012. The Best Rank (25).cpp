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

#include <climits>
#include <string>
#include <vector>
#include <map>

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

	struct Student {
		string id;
		int score[4];
		int best;
		int type;
	};
	const char type_list[4] = {'A', 'C', 'M', 'E'};
	int stu_num, check_num;
	while (cin >> stu_num >> check_num) {
		map<string, Student> stu_list;
		map<int, size_t, std::greater<int> > score_list[4];
		for (int i = 0; i < stu_num; ++ i) {
			string id;
			int c, m, e;
			cin >> id >> c >> m >> e;
			stu_list[id].id = id;
			stu_list[id].score[1] = c;
			stu_list[id].score[2] = m;
			stu_list[id].score[3] = e;
			stu_list[id].score[0] = c + m + e;
			stu_list[id].best = INT_MAX;
			++ score_list[1][c];
			++ score_list[2][m];
			++ score_list[3][e];
			++ score_list[0][c + m + e];
		}
		for (map<string, Student>::iterator it1 = stu_list.begin(); it1 != stu_list.end(); ++ it1) {
			for (int j = 0; j < 4; ++ j) {
				int count = 0;
				for (map<int, size_t, std::greater<int> >::iterator it = score_list[j].begin(); it != score_list[j].end(); ++ it) {
					// may have duplicate
					if (it1->second.score[j] == it->first && it1->second.best > count + 1) {
						it1->second.best = count + 1;
						it1->second.type = j;
					}
					count += it->second;
				}
			}
		}
		for (int i = 0; i < check_num; ++ i) {
			string id;
			cin >> id;
			if (stu_list.end() == stu_list.find(id)) {
				cout << "N/A" << endl;
			}
			else {
				cout << stu_list[id].best << " " << type_list[stu_list[id].type] << endl;
			}
		}
	}

	return 0;
}


















