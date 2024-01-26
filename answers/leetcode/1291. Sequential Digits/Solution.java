class Solution {
    private SortedSet<Integer> SEQUENTIAL = new TreeSet<>();

    public Solution() {
        final int MAX = 1_000_000_000;
        for (int i = 1; i <= 9; i++) {
            int digit = i;
            int number = 0;
            while (digit <= 9) {
                number = number * 10 + digit;
                digit++;
                if (number > MAX) {
                    break;
                }
                SEQUENTIAL.add(number);
            }
        }
    }

    public List<Integer> sequentialDigits(int low, int high) {
        SortedSet<Integer> range = SEQUENTIAL.subSet(low, high + 1);
        return new LinkedList<>(range);
    }
}