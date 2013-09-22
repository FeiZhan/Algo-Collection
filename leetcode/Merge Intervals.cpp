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
