//@type Depth-first Search Breadth-first Search Graph Topological Sort
//@result 35 / 35 test cases passed. Status: Accepted Runtime: 1180 ms Submitted: 0 minutes ago You are here! Your runtime beats 0.85% of cpp submissions.

#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, set<int> > pre_map;
		for (int i = 0; i < numCourses; ++ i) {
			pre_map.insert(make_pair(i, set<int> ()));
		}
		for (size_t i = 0; i < prerequisites.size(); ++ i) {
			pre_map[prerequisites[i].first].insert(prerequisites[i].second);
		}
		vector<int> order_list;
		while (order_list.size() < numCourses) {
			bool flag(false);
			for (map<int, set<int> >::iterator it = pre_map.begin(); it != pre_map.end();) {
				if (it->second.size() == 0) {
					flag = true;
					order_list.push_back(it->first);
					for (map<int, set<int> >::iterator it1 = pre_map.begin(); it1 != pre_map.end(); ++ it1) {
						for (set<int>::iterator it2 = it1->second.begin(); it2 != it1->second.end();) {
							if (it->first == *it2) {
								it1->second.erase(it2 ++);
							}
							else {
								 ++ it2;
							}
						}
					}
					pre_map.erase(it ++);
				}
				else {
					++ it;
				}
			}
			if (! flag) {
				order_list.clear();
				break;
			}
		}
		return order_list;
    }
};

int main() {
	Solution s;
	//10
	//[[5,8],[3,5],[1,9],[4,5],[0,2],[1,9],[7,8],[4,9]]
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back(make_pair(5, 8));
	prerequisites.push_back(make_pair(3, 5));
	prerequisites.push_back(make_pair(1, 9));
	prerequisites.push_back(make_pair(4, 5));
	prerequisites.push_back(make_pair(0, 2));
	prerequisites.push_back(make_pair(1, 9));
	prerequisites.push_back(make_pair(7, 8));
	prerequisites.push_back(make_pair(4, 9));
	vector<int> order = s.findOrder(10, prerequisites);
	for (size_t i = 0; i < order.size(); ++ i) {
		cout << order[i] << endl;
	}
	return 0;
}