class Solution {
    private static final SortedSet<Integer> PUNISHMENT = new TreeSet<>();

    public Solution() {
        for (int i = 1; i <= 1000; i++) {
            if (this.check(i)) {
                PUNISHMENT.add(i);
            }
        }
    }

    public int punishmentNumber(int n) {
        int result = 0;
        SortedSet<Integer> subset = PUNISHMENT.headSet(n + 1);
        for (int number : subset) {
            result += number * number;
        }

        return result;
    }

    private boolean check(int number) {
        int square = number * number;
        List<Integer> digits = new LinkedList<>();
        while (square > 0) {
            digits.add(0, square % 10);
            square /= 10;
        }
        return this.check(0, digits, number);
    }

    private boolean check(int index, List<Integer> digits, int target) {
        if (index >= digits.size()) {
            return target == 0;
        }

        int left = 0;
        for (int i = index; i < digits.size(); i++) {
            left = left * 10 + digits.get(i);
            if (this.check(i + 1, digits, target - left)) {
                return true;
            }
        }

        return false;
    }
}