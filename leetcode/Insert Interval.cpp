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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> vec;
		for (int i = 0; i < intervals.size(); ++ i)
		{
			/*if (intervals[i].size() < 2)
			{
				intervals.erase(i, 1);
				continue;
			}*/
			vec.push_back(intervals[i].start);
			vec.push_back(intervals[i].end);
		}
		int pos1 = bSearch(vec, newInterval.start);
		int pos2 = bSearch(vec, newInterval.end);
		vector<Interval> ans;
		for (int i = 0; i + 1 < pos1; i += 2)
		{
			ans.push_back(Interval(vec[i], vec[i + 1]));
		}
		ans.push_back(Interval(vec[pos1], vec[(pos2 % 2) ? pos2 + 1 : pos2]));
		for (int i = (pos2 % 2) ? pos2 + 1 : pos2; i + 1 < intervals.size(); i += 2)
		{
			ans.push_back(Interval(vec[i], vec[i + 1]));
		}
		return ans;
    }
    int bSearch(const vector<int> &vec, const int val)
    {
		int low = 0;
		int high = vec.size();
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (vec[mid] > val)
			{
				high = mid - 1;
			} else if (vec[mid] < val)
			{
				low = mid + 1;
			} else
			{
				return mid;
			}
		}
		return (low + high) / 2;
	}
};
