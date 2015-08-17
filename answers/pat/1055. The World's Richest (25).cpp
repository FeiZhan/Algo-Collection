// 2	运行超时
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
#include <set>
#include <map>
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

	struct Person {
		string name;
		int age;
		int worth;
		Person(const string &n, int a, int w) : name(n), age(a), worth(w)
		{}
		bool operator< (const struct Person &p) const
		{
			if (worth > p.worth) return true;
			if (worth < p.worth) return false;
			if (age < p.age) return true;
			if (age > p.age) return false;
			if (name < p.name) return true;
			if (name > p.name) return false;
			return false;
		}
	};
	int people_num, query_num;
	while (cin >> people_num >> query_num) {
		vector<Person> people_list;
		map<int, multiset<size_t> > age_map;
		for (int i = 0; i < people_num; ++ i) {
			string name;
			int age;
			int worth;
			cin >> name >> age >> worth;
			people_list.push_back(Person(name, age, worth));
		}
		sort(people_list.begin(), people_list.end());
		for (size_t i = 0; i < people_list.size(); ++ i) {
			age_map[people_list[i].age].insert(i);
		}
		for (int i = 0; i < query_num; ++ i) {
			int output, age_min, age_max;
			cin >> output >> age_min >> age_max;
			//cout << "Case #" << i + 1 << ":" << endl;
			printf("Case #%d:\n", i + 1);
			map<int, multiset<size_t> >::iterator lower_it = age_map.lower_bound(age_min);
			map<int, multiset<size_t> >::iterator upper_it = age_map.upper_bound(age_max);
			multiset<size_t> people_set;
			for (map<int, multiset<size_t> >::iterator it = lower_it; it != upper_it; ++ it) {
				int count = 0;
				for (multiset<size_t>::iterator it1 = it->second.begin(); it1 != it->second.end(); ++ it1) {
					++ count;
					if (count > output) {
						break;
					}
					people_set.insert(*it1);
				}
			}
			int count = 0;
			for (multiset<size_t>::iterator it = people_set.begin(); it != people_set.end(); ++ it) {
				++ count;
				if (count > output) {
					break;
				}
				//cout << people_list[*it].name << " " << people_list[*it].age << " " << people_list[*it].worth << endl;
				printf("%s %d %d\n", people_list[*it].name.c_str(), people_list[*it].age, people_list[*it].worth);
			}
			if (0 == count) {
				cout << "None" << endl;
			}
		}
	}

	return 0;
}



