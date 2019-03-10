class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs,
            Comparator.comparing((int[] pair) -> pair[1])
            .thenComparing(Comparator.comparing((int[] pair) -> pair[0])));
        int count = 0;
        int end = Integer.MIN_VALUE;
        for (int[] pair : pairs) {
            if (pair[0] > end) {
                count++;
                end = pair[1];
            }
        }
        return count;
    }
}