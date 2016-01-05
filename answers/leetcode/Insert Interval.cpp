//@result 151 / 151 test cases passed. Status: Accepted Runtime: 580 ms Submitted: 1 minute ago You are here! Your runtime beats 65.83% of cpp submissions.

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
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ans;
		size_t i = 0;
		for (i = 0; i < intervals.size() && intervals[i].end < newInterval.start; ++i) {
			ans.push_back(intervals[i]);
		}
		for (; i < intervals.size() && intervals[i].start <= newInterval.end; ++i) {
			newInterval.start = std::min(newInterval.start, intervals[i].start);
			newInterval.end = std::max(newInterval.end, intervals[i].end);
		}
		ans.push_back(newInterval);
		for (; i < intervals.size(); ++i) {
			ans.push_back(intervals[i]);
		}
		return ans;
	}
};
