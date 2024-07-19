class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(interval -> interval[0]));
        LinkedList<int[]> result = new LinkedList<>();

        for (int[] interval : intervals) {
            if (result.size() == 0) {
                result.add(interval);
            } else {
                int[] last = result.getLast();
                if (last[1] < interval[0]) {
                    result.add(interval);
                } else {
                    last[1] = Math.max(last[1], interval[1]);
                }
            }
        }

        return result.toArray(new int[result.size()][]);
    }
}
//Runtime: 7 ms, faster than 44.83% of Java online submissions for Merge Intervals.
//Memory Usage: 41.2 MB, less than 98.82% of Java online submissions for Merge Intervals.
