//
#include <iostream>
using namespace std;

#include <string>
#include <set>
#include <map>

int dfs(const string &current, set<string> &visit_list, map<string, pair<int, set<string> > > &gang_map, string &head, int &count) {
	visit_list.insert(current);
	int weight = gang_map[current].first;
	head = current;
	count = 1;
	for (set<string>::iterator it = gang_map[current].second.begin(); it != gang_map[current].second.end(); ++ it) {
		if (visit_list.end() == visit_list.find(*it)) {
			string local_head;
			int local_count(0);
			weight += dfs(*it, visit_list, gang_map, local_head, local_count);
			count += local_count;
			if (gang_map[head].first < gang_map[local_head].first) {
				head = local_head;
			}
		}
	}
	return weight;
}
int main (int argc, char *argv[])
{
	int call_num(0), threshold(0);
	while (cin >> call_num >> threshold) {
		map<string, pair<int, set<string> > > gang_map;
		for (int i = 0; i < call_num; ++ i) {
			string name0, name1;
			int time(0);
			cin >> name0 >> name1 >> time;
			if (gang_map.end() == gang_map.find(name0)) {
				gang_map.insert(make_pair(name0, make_pair(0, set<string> ())));
			}
			gang_map[name0].first += time;
			gang_map[name0].second.insert(name1);
			if (gang_map.end() == gang_map.find(name1)) {
				gang_map.insert(make_pair(name1, make_pair(0, set<string> ())));
			}
			gang_map[name1].first += time;
			gang_map[name1].second.insert(name0);
		}
		set<string> visit_list;
		map<string, int> head_list;
		for (map<string, pair<int, set<string> > >::iterator it = gang_map.begin(); it != gang_map.end(); ++ it) {
			if (visit_list.end() == visit_list.find(it->first)) {
				string head;
				int count(0);
				int weight = dfs(it->first, visit_list, gang_map, head, count);
				if (count > 2 && weight > 2 * threshold) {
					head_list.insert(make_pair(head, count));
					//cout << "test " << head << " " << count << " " << weight << endl;
				}
			}
		}
		cout << head_list.size() << endl;
		for (map<string, int>::iterator it = head_list.begin(); it != head_list.end(); ++ it) {
			cout << it->first << " " << it->second << endl;
		}
	}

	return 0;
}