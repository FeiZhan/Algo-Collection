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
    public List<Interval> merge(List<Interval> intervals) {
        Collections.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                return i1.start - i2.start;
            }
        });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals.get(i).start <= intervals.get(i - 1).end) {
                intervals.get(i - 1).end = Math.max(intervals.get(i - 1).end, intervals.get(i).end);
                intervals.remove(i);
                i--;
            }
        }
        return intervals;
    }
}