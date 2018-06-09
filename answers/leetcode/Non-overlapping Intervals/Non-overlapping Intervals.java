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
    public int eraseOverlapIntervals(Interval[] intervals) {
        Arrays.sort(intervals, Comparator.comparing(interval -> interval.start));
        int count = 0;
        int end = Integer.MIN_VALUE;
        for (Interval i : intervals) {
            if (i.start < end) {
                end = Math.min(end, i.end);
                count++;
            } else {
                end = i.end;
            }
        }
        return count;
    }
}