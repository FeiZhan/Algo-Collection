class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        int length = A.length;
        Map<Integer, Integer> aCounts = new HashMap<>();
        Map<Integer, Integer> bCounts = new HashMap<>();
        for (int i = 0; i < length; i++) {
            aCounts.put(A[i], aCounts.getOrDefault(A[i], 0) + 1);
            bCounts.put(B[i], bCounts.getOrDefault(B[i], 0) + 1);
        }
        Set<Integer> full = new HashSet<>();
        full.add(A[0]);
        full.add(B[0]);
        for (int i = 1; i < length; i++) {
            Set<Integer> current = new HashSet<>();
            current.add(A[i]);
            current.add(B[i]);
            full.retainAll(current);
        }
        int min = Integer.MAX_VALUE;
        for (int number : full) {
            min = Math.min(min, length - Math.max(aCounts.getOrDefault(number, 0), bCounts.getOrDefault(number, 0)));
        }
        return min < Integer.MAX_VALUE ? min : -1;
    }
}