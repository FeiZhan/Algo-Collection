class Solution {
    public int minDeletionSize(String[] A) {
        int count = 0;
        int length = A[0].length();
        Map<Integer, Integer> ranges = new HashMap<>();
        ranges.put(0, A.length - 1);
        for (int i = 0; i < length; i++) {
            if (ranges.isEmpty()) {
                break;
            }
            boolean needDelete = false;
            Map<Integer, Integer> nextRanges = new HashMap<>();
            for (int start : ranges.keySet()) {
                int previous = start;
                int end = ranges.get(start);
                for (int j = start + 1; j <= end; j++) {
                    int compare = A[j].charAt(i) - A[j - 1].charAt(i);
                    if (compare < 0) {
                        count++;
                        needDelete = true;
                        break;
                    } else if (compare > 0) {
                        if (j - 1 > previous) {
                            nextRanges.put(previous, j - 1);
                        }
                        previous = j;
                    }
                }
                if (needDelete) {
                    break;
                }
                if (end > previous) {
                    nextRanges.put(previous, end);
                }
            }
            if (!needDelete) {
                ranges = nextRanges;
            }
        }
        return count;
    }
}