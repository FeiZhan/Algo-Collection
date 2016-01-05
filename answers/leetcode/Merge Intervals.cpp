// 2015-01-10
//@result 168 / 168 test cases passed. Status: Accepted Runtime: 596 ms Submitted: 0 minutes ago You are here! Your runtime beats 19.87% of cpp submissions.

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		multimap<int, Interval> int_map;
		for (size_t i = 0; i < intervals.size(); ++i) {
			int_map.insert(make_pair(intervals[i].start, intervals[i]));
		}
		vector<Interval> ans;
		for (multimap<int, Interval>::iterator it = int_map.begin(); it != int_map.end();) {
			if (int_map.end() != std::next(it) && it->second.end >= std::next(it)->second.start) {
				it->second.end = std::max(it->second.end, std::next(it)->second.end);
				int_map.erase(std::next(it));
			}
			else {
				ans.push_back(it->second);
				++it;
			}
		}
		return ans;
	}
};
