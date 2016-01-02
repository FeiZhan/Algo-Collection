//@type Divide and Conquer Heap
//@result 33 / 33 test cases passed. Status: Accepted Runtime: 900 ms Submitted: 6 minutes ago You are here! Your runtime beats 14.27% of cpp submissions.

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings) {
        map<int, multimap<int, bool> > build_map;
		// set the height for each point in x-axis
		for (size_t i = 0; i < buildings.size(); ++ i) {
			if (build_map.end() == build_map.find(buildings[i][0])) {
				build_map.insert(make_pair(buildings[i][0], multimap<int, bool> ()));
			}
			// extrude
			build_map[ buildings[i][0] ].insert(make_pair(buildings[i][2], true));
			if (build_map.end() == build_map.find(buildings[i][1])) {
				build_map.insert(make_pair(buildings[i][1], multimap<int, bool> ()));
			}
			// flat
			build_map[ buildings[i][1] ].insert(make_pair(buildings[i][2], false));
		}
		vector<pair<int, int> > skyline;
		multiset<int> current_heights;
		for (map<int, multimap<int, bool> >::iterator it = build_map.begin(); it != build_map.end(); ++ it) {
			bool flag(false);
			for (multimap<int, bool>::iterator it1 = it->second.begin(); it1 != it->second.end(); ++ it1) {
				if (it1->second) {
					current_heights.insert(it1->first);
				}
				else { // remove the flat point
					pair<multiset<int>::iterator, multiset<int>::iterator> pit = current_heights.equal_range(it1->first);
					if( distance( pit.first, pit.second ) > 0 ) {
						// if removing the top
						if (next(pit.first) == current_heights.end()) {
							flag = true;
						}
						current_heights.erase( pit.first );
					}
				}
			}
			if (current_heights.size() && (0 == skyline.size() || *current_heights.rbegin() != skyline.rbegin()->second)) {
				skyline.push_back(make_pair(it->first, *current_heights.rbegin()));
			}
			// if the top is removed, the height becomes zero
			else if (flag) {
				skyline.push_back(make_pair(it->first, 0));
			}
		}
		int current(0);
		// double check
		for (size_t i = 0; i < skyline.size(); ++ i) {
			if (skyline[i].second == current) {
				skyline[i].second = 0;
				if (0 == skyline[i - 1].second) {
					skyline.erase(skyline.begin() + i - 1);
					-- i;
				}
			}
			else {
				current = skyline[i].second;
			}
		}
		return skyline;
    }
};