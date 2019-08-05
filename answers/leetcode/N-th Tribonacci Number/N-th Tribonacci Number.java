class Solution {
    private Map<Integer, Integer> results = new HashMap<>();

    public Solution() {
        this.results.put(0, 0);
        this.results.put(1, 1);
        this.results.put(2, 1);
    }

    public int tribonacci(int n) {
        if (!this.results.containsKey(n)) {
            this.results.put(n, this.tribonacci(n - 3) + this.tribonacci(n - 2) + this.tribonacci(n - 1));
        }
        return this.results.get(n);
    }
}