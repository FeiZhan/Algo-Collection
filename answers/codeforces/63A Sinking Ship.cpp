//@type simple, implementation, sortings, strings
//@result 12795897	2015-09-01 04:19:49	zetta217	63A - Sinking Ship	GNU C++	Accepted	30 ms	0 KB

#include <iostream>
using namespace std;
#include <set>

struct Person {
	int status;
	int number;
	string name;
	Person(int n, const string na, const string &s) : number(n), name(na) {
		if (string("rat") == s) {
			status = 0;
		}
		else if (string("woman") == s) {
			status = 1;
		}
		else if (string("child") == s) {
			status = 1;
		}
		else if (string("man") == s) {
			status = 3;
		}
		else if (string("captain") == s) {
			status = 5;
		}
		else {
			status = 4;
		}
	}
};
inline bool operator <(const Person &lhs, const Person &rhs) {
	if (lhs.status != rhs.status) {
		return lhs.status < rhs.status;
	}
	else if (lhs.number != rhs.number) {
		return lhs.number < rhs.number;
	}
	else {
		return lhs.name < rhs.name;
	}
}
int main() {
	int people_num(0);
	while (cin >> people_num) {
		multiset<Person> person_list;
		for (int i = 0; i < people_num; ++ i) {
			string s;
			string na;
			cin >> na >> s;
			person_list.insert(Person(i, na, s));
		}
		for (multiset<Person>::iterator it = person_list.begin(); it != person_list.end(); ++ it) {
			cout << it->name << endl;
		}
	}
	return 0;
}