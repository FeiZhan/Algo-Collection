/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        if (intervals == null) {
            intervals = new ArrayList<>();
        }
        if (intervals.size() == 0) {
            intervals.add(newInterval);
        } else {
            int newIndex = -1;
            for (int i = 0; i < intervals.size(); i++) {
                if (newIndex == -1) {
                    if (newInterval.start < intervals.get(i).start) {
                        intervals.add(i, newInterval);
                        newIndex = i;
                    } else if (newInterval.start <= intervals.get(i).end) {
                        intervals.get(i).start = Math.min(intervals.get(i).start, newInterval.start);
                        intervals.get(i).end = Math.max(intervals.get(i).end, newInterval.end);
                        newIndex = i;
                    }
                } else if (newIndex >= 0) {
                    if (intervals.get(newIndex).end >= intervals.get(i).start) {
                        intervals.get(newIndex).end = Math.max(intervals.get(newIndex).end, intervals.get(i).end);
                        intervals.remove(i);
                        i--;
                    } else {
                        break;
                    }
                }
            }
            if (newIndex < 0) {
                intervals.add(newInterval);
            }
        }
        return intervals;
    }
}