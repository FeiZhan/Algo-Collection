class Solution {

    private static final Map<Integer, Integer> DIGIT_SUMS = new HashMap<>();

    static {
        for (int i = 0; i <= 10000; i++) {
            int digits = 0;
            int number = i;
            while (number != 0) {
                digits += number % 10;
                number /= 10;
            }
            DIGIT_SUMS.put(i, digits);
        }
    }

    public int countLargestGroup(int n) {
        Map<Integer, Integer> groups = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            int digits = DIGIT_SUMS.getOrDefault(i, -1);
            groups.put(digits, groups.getOrDefault(digits, 0) + 1);
        }
        int count = 0;
        int largest = 0;
        for (int value : groups.values()) {
            if (value > largest) {
                largest = value;
                count = 0;
            }
            if (value == largest) {
                count++;
            }
        }
        return count;
    }
}