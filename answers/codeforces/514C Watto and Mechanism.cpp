//@type binary search, hashing, string suffix structures, strings
//@result 12780168	2015-08-30 20:55:42	zetta217	514C - Watto and Mechanism	GNU C++	Wrong answer on test 6	15 ms	200 KB
#include <iostream>
using namespace std;

#include <string>
#include <set>

int main() {
	int str_num(0);
	int query_num(0);
	while (cin >> str_num >> query_num) {
		set<string> str_list;
		set<string> equal_list;
		for (int i = 0; i < str_num; ++ i) {
			string str;
			cin >> str;
			str_list.insert(str);
			for (size_t j = 0; j < str.length(); ++ j) {
				string temp(str);
				temp.erase(j, 1);
				equal_list.insert(temp);
			}
		}
		for (int i = 0; i < query_num; ++ i) {
			string query;
			cin >> query;
			bool find_flag(false);
			if (str_list.end() != str_list.find(query)) {
				cout << "NO" << endl;
				continue;
			}
			for (size_t j = 0; j < query.length(); ++ j) {
				string temp(query);
				temp.erase(j, 1);
				if (equal_list.end() != equal_list.find(temp)) {
					cout << "YES" << endl;
					find_flag = true;
					break;
				}
			}
			if (! find_flag) {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}