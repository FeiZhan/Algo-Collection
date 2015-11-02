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
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        size_t insert_index = intervals.size();
        for (size_t i = 0; i < intervals.size(); ++ i) {
        	if (newInterval.start <= intervals[i].start) {
        		insert_index = i;
        		break;
        	}
        }
        while (insert_index < intervals.size() && newInterval.end >= intervals[insert_index].start) {
        	newInterval.end = max(newInterval.end, intervals[insert_index].end);
        	intervals.erase(intervals.begin() + insert_index);
        }
        if (insert_index > 0 && newInterval.start <= intervals[insert_index - 1].end) {
        	intervals[insert_index - 1].end = max(intervals[insert_index - 1].end, newInterval.end);
        }
        else {
        	intervals.insert(intervals.begin() + insert_index, newInterval);
        }
        return intervals;
    }
};
