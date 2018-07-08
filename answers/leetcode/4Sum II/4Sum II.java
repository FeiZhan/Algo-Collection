class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> ab = new HashMap<>();
        for (int a : A) {
            for (int b : B) {
                int sum = a + b;
                ab.put(sum, ab.getOrDefault(sum, 0) + 1);
            }
        }
        int count = 0;
        for (int c : C) {
            for (int d : D) {
                count += ab.getOrDefault(- c - d, 0);
            }
        }
        return count;
    }
}