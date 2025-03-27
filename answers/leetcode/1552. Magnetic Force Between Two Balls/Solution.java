class Solution {
    public int maxDistance(int[] position, int m) {
        int minPosition = Integer.MAX_VALUE;
        int maxPosition = 0;
        SortedSet<Integer> positionSet = new TreeSet<>();
        for (int p : position) {
            minPosition = Math.min(minPosition, p);
            maxPosition = Math.max(maxPosition, p);
            positionSet.add(p);
        }
        int left = 1;
        int right = maxPosition;
        while (left <= right) {
            int middle = (left + right) / 2;
            int count = 0;
            for (int i = minPosition; i <= maxPosition; i += middle) {
                SortedSet<Integer> set = positionSet.tailSet(i);
                if (set.isEmpty()) {
                    break;
                }
                i = set.first();
                count++;
                if (count >= m) {
                    break;
                }
            }
            //System.out.println(left + " " + middle + " " + right + ": " + count);
            if (count >= m) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return right;
    }
}