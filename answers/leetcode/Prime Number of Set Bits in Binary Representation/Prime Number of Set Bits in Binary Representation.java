class Solution {
    private static final Set<Integer> PRIME = new HashSet<>(Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19));

    private Map<Integer, Boolean> results = new HashMap<>();

    public int countPrimeSetBits(int L, int R) {
        int count = 0;
        for (int i = L; i <= R; i++) {
            if (!this.results.containsKey(i)) {
                this.results.put(i, PRIME.contains(Integer.bitCount(i)));
            }
            if (this.results.get(i)) {
                count++;
            }
        }
        return count;
    }
}