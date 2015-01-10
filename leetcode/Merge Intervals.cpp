// copied from leetcode

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Comp {
public:
	bool operator()(const Interval &i1, const Interval &i2)
	{
		return i1.start < i2.start;
	}
};
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<Interval> res;
		// sort based on start
		std::sort(intervals.begin(), intervals.end(), Comp());
		int k = 0;
		while (k < intervals.size())
		{
			res.push_back(intervals[k ++]);
			// check all overlap
			while (k < intervals.size() && intervals[k].start <= res.back().end)
			{
				// merge overlap
				if (res.back().end < intervals[k].end)
				{
					res.back().end = intervals[k ++].end;
				} else
				{
					++ k;
				}
			}
		}
		return res;
    }
};

// 2015-01-10
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