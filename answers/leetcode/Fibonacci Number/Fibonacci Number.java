class Solution {
    private Map<Integer, Integer> numbers = new HashMap<>();

    public int fib(int N) {
        if (!this.numbers.containsKey(N)) {
            int result = 0;
            if (N <= 1) {
                result = N;
            } else {
                result = this.fib(N - 1) + this.fib(N - 2);
            }
            this.numbers.put(N, result);
        }
        return this.numbers.get(N);
    }
}