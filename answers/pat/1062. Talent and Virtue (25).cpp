//
#include <cstdio>
#include <iostream>
using namespace std;

#include <climits>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

struct Person {
	int id;
	int virtue;
	int talent;
	int type;
	Person(void) : id(), virtue(0), talent(0), type(0) {}
	Person(int i, int v, int t, int ty = 0) : id(i), virtue(v), talent(t), type(ty) {}
};
std::ostream& operator <<(std::ostream &o, const Person& p) {
	return o << std::setfill('0') << std::setw(8) << p.id << " " << p.virtue << " " << p.talent;
}
bool operator <(const Person& lhs, const Person& rhs) {
	if (lhs.type != rhs.type) {
		return lhs.type < rhs.type;
	}
	else if (lhs.virtue + lhs.talent != rhs.virtue + rhs.talent) {
		return lhs.virtue + lhs.talent < rhs.virtue + rhs.talent;
	}
	else if (lhs.virtue != rhs.virtue) {
		return lhs.virtue < rhs.virtue;
	}
	else {
		return lhs.id > rhs.id;
	}
}

int main (int argc, char *argv[])
{
	int people_num(0), lower(0), higher(0);
	while (cin >> people_num >> lower >> higher) {
		vector<Person> person_list;
		for (int i = 0; i < people_num; ++ i) {
			Person p;
			cin >> p.id >> p.virtue >> p.talent;
			if (p.virtue >= higher && p.talent >= higher) {
				p.type = 4;
			}
			else if (p.virtue >= higher && p.talent < higher && p.talent >= lower) {
				p.type = 3;
			}
			else if (p.virtue < higher && p.virtue >= lower && p.talent < higher && p.talent >= lower && p.virtue >= p.talent) {
				p.type = 2;
			}
			else if (p.virtue >= lower && p.talent >= lower) {
				p.type = 1;
			}
			else {
				p.type = 0;
				continue;
			}
			person_list.push_back(p);
		}
		sort(person_list.begin(), person_list.end());
		cout << person_list.size() << endl;
		for (size_t i = person_list.size() - 1; i < INT_MAX; -- i) {
			//cout << person_list[i] << endl;
			printf("%08d %d %d\n", person_list[i].id, person_list[i].virtue, person_list[i].talent);  
		}
	}

	return 0;
}