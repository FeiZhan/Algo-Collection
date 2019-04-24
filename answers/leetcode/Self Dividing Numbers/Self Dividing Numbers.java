class Solution {
    private Map<Integer, Boolean> numbers = new HashMap<>();

    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> results = new LinkedList<>();
        for (int i = left; i <= right; i++) {
            if (!this.numbers.containsKey(i)) {
                int number = i;
                while (number != 0) {
                    int digit = number % 10;
                    if (digit == 0 || i % digit != 0) {
                        break;
                    }
                    number /= 10;
                }
                this.numbers.put(i, number == 0);
            }
            if (this.numbers.get(i)) {
                results.add(i);
            }
        }
        return results;
    }
}