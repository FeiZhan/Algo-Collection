//WA
#include <iostream>
using namespace std;

#include <iomanip>
#include <climits>
#include <string>
#include <vector>
#include <set>
#include <map>

struct Time {
	int hour;
	int minute;
	int second;
	Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
};
bool operator ==(const Time &lhs, const Time &rhs) {
	return lhs.hour == rhs.hour && lhs.minute == rhs.minute && lhs.second == rhs.second;
}
bool operator !=(const Time &lhs, const Time &rhs) {
	return ! (lhs == rhs);
}
bool operator <(const Time &lhs, const Time &rhs) {
	if (lhs.hour != rhs.hour) {
		return lhs.hour < rhs.hour;
	}
	else if (lhs.minute != rhs.minute) {
		return lhs.minute < rhs.minute;
	}
	else {
		return lhs.second < rhs.second;
	}
}
bool operator <=(const Time &lhs, const Time &rhs) {
	return lhs < rhs || lhs == rhs;
}
Time operator +(const Time &lhs, const Time &rhs) {
	Time output;
	output.second += lhs.second + rhs.second;
	if (output.second >= 60) {
		output.minute += output.second / 60;
		output.second %= 60;
	}
	output.minute += lhs.minute + rhs.minute;
	if (output.minute >= 60) {
		output.hour += output.minute / 60;
		output.minute %= 60;
	}
	output.hour += lhs.hour + rhs.hour;
	return output;
}
std::ostream& operator <<(std::ostream &o, const Time &p) {
	return o << std::setw(2) << std::setfill('0') << p.hour << ":" << std::setw(2) << std::setfill('0') << p.minute << ":" << std::setw(2) << std::setfill('0') << p.second;
}

struct Pair {
	Time time;
	int duration;
	bool vip;
	Pair(void) : time(), duration(0), vip(false) {}
};
bool operator <(const Pair &lhs, const Pair &rhs) {
	return lhs.time < rhs.time;
}
std::ostream& operator <<(std::ostream &o, const Pair &p) {
	return o << p.time << " duration " << p.duration << " vip " << p.vip;
}

struct Table {
	int num;
	bool vip;
	Time time;
	int pair_num;
	Table(int n, bool v = false) : num(n), time(), pair_num(0), vip(v) {}
};
bool operator <(const Table &lhs, const Table &rhs) {
	if (lhs.time != rhs.time) {
		return lhs.time < rhs.time;
	}
	else {
		return lhs.num < rhs.num;
	}
}
std::ostream& operator <<(std::ostream &o, const Table &t) {
	return o << t.num << " vip " << t.vip << " time " << t.time << " num " << t.pair_num;
}

int main (int argc, char *argv[])
{
	int pair_num(0);
	while (cin >> pair_num) {
		set<Pair> pair_list;
		string arrive;
		for (int i = 0; i < pair_num; ++ i) {
			Pair p;
			cin >> arrive >> p.duration >> p.vip;
			p.time.hour = static_cast<int> (arrive[0] - '0') * 10 + static_cast<int> (arrive[1] - '0');
			p.time.minute = static_cast<int> (arrive[3] - '0') * 10 + static_cast<int> (arrive[4] - '0');
			p.time.second = static_cast<int> (arrive[6] - '0') * 10 + static_cast<int> (arrive[7] - '0');
			if (p.duration > 120) {
				p.duration = 120;
			}
			pair_list.insert(p);
		}
		int table_num(0), vip_table_num(0);
		cin >> table_num >> vip_table_num;
		vector<Table> table_list;
		for (int i = 0; i < table_num; ++ i) {
			Table t(i + 1, false);
			t.time.hour = 8;
			table_list.push_back(t);
		}
		for (int i = 0; i < vip_table_num; ++ i) {
			int vip_table(0);
			cin >> vip_table;
			table_list[vip_table - 1].vip = true;
		}
		set<Table> table_set(table_list.begin(), table_list.end());
		for (set<Pair>::iterator it = pair_list.begin(); it != pair_list.end(); ++ it) {
			if (it->time.hour >= 21) {
				break;
			}
			set<Pair>::iterator pair_it = it;
			//cout << "pair " << *pair_it << " " << pair_it->time + Time(0, pair_it->duration, 0) << endl;
			Table t(INT_MAX, false);
			t.time = pair_it->time;
			set<Table>::iterator lower = table_set.lower_bound(t);
			set<Table>::iterator min_it = table_set.begin();
			for (set<Table>::iterator it1 = table_set.begin(); it1 != lower && it1 != table_set.end(); ++ it1) {
				if (((pair_it->vip && it1->vip) || ! pair_it->vip) && min_it->num > it1->num) {
					min_it = it1;
				}
			}
			if (min_it->time.hour >= 21) {
				break;
			}
			if (min_it->vip) {
				for (set<Pair>::iterator it2 = it; it2->time <= min_it->time && it2 != pair_list.end(); ++ it2) {
					if (it2->vip) {
						pair_it = it2;
						break;
					}
				}
				//cout << "vip " << *it1 << " " << *pair_it << endl;
			}
			int wait_time(0);
			Time start_time;
			Table table_min(*min_it);
			if (pair_it->time < table_min.time) {
				start_time = min_it->time;
			}
			else {
				start_time = pair_it->time;
			}
			if (start_time.hour >= 21) {
				break;
			}
			table_min.time = start_time + Time(0, pair_it->duration, 0);
			if (table_min.time.hour >= 21) {
			}
			else {
			}
			wait_time = (start_time.hour - pair_it->time.hour) * 60 + start_time.minute - pair_it->time.minute + (start_time.second - pair_it->time.second) / 30;
			cout << pair_it->time << " " << start_time << " " << wait_time << endl;
			if (pair_it->vip) {
				-- it;
				pair_list.erase(pair_it);
			}
			++ table_min.pair_num;
			//cout << "table " << table_min << endl;
			table_set.erase(min_it);
			table_set.insert(table_min);
		}
		bool first_flag = true;
		for (set<Table>::iterator it = table_set.begin(); it != table_set.end(); ++ it) {
			if (first_flag) {
				first_flag = false;
			}
			else {
				cout << " ";
			}
			cout << it->pair_num;
		}
		cout << endl;
	}

	return 0;
}