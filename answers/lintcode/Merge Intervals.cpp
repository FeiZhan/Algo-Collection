/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
		sort(intervals.begin(), intervals.end(), [] (const Interval &a, const Interval &b) -> bool {
			return a.start < b.start; 
		});
		for (size_t i = 1; i < intervals.size(); ++ i) {
			if (intervals[i - 1].end >= intervals[i].start) {
				intervals[i - 1].end = max(intervals[i - 1].end, intervals[i].end);
				intervals.erase(intervals.begin() + i);
				-- i;
			}
		}
		return intervals;
    }
};
