class Solution {

    private Map<Integer, Integer> threes = new HashMap<>();
    private Map<Integer, Integer> results = new HashMap<>();

    public Solution() {
        this.threes.put(0, 0);
        this.threes.put(1, 1);
        this.threes.put(2, 2);
        this.threes.put(3, 6);
        this.results.put(0, 0);
        this.results.put(1, 1);
        this.results.put(2, 2);
        this.results.put(3, 6);
    }

    public int clumsy(int N) {
        if (!this.results.containsKey(N)) {
            this.results.put(N, this.getThree(N) + N - 3 - 2 * this.getThree(N - 4) + this.clumsy(N - 4));
        }
        return this.results.get(N);
    }

    private int getThree(int number) {
        if (!this.threes.containsKey(number)) {
            this.threes.put(number, number * (number - 1) / (number - 2));
        }
        return this.threes.get(number);
    }
}