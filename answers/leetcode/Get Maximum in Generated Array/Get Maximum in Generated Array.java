class Solution {
    private List<Integer> numbers = new ArrayList<>();
    private List<Integer> maxNumbers = new ArrayList<>();

    public int getMaximumGenerated(int n) {
        int max = this.maxNumbers.isEmpty() ? 0 : this.maxNumbers.get(this.maxNumbers.size() - 1);
        for (int i = numbers.size(); i <= n; i++) {
            int number = this.getNumber(i);
            this.numbers.add(number);
            max = Math.max(max, number);
            this.maxNumbers.add(max);
        }
        return this.maxNumbers.get(n);
    }

    private int getNumber(int n) {
        if (n <= 1) {
            return n;
        } else if (n % 2 == 0) {
            return this.numbers.get(n / 2);
        } else {
            return this.numbers.get(n / 2) + this.numbers.get(n / 2 + 1);
        }
    }
}
//Runtime: 1 ms, faster than 28.10% of Java online submissions for Get Maximum in Generated Array.
//Memory Usage: 35.9 MB, less than 47.02% of Java online submissions for Get Maximum in Generated Array.
