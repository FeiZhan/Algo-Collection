class Solution {

    private Map<Integer, Boolean> numbers = new HashMap<>();

    public int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (!this.numbers.containsKey(i)) {
                boolean change = false;
                boolean good = true;
                int number = i;
                while (number > 0) {
                    int digit = number % 10;
                    switch (digit) {
                        case 2:
                        case 5:
                        case 6:
                        case 9:
                            change = true;
                            break;
                        case 3:
                        case 4:
                        case 7:
                            good = false;
                            break;
                    }
                    if (!good) {
                        break;
                    }
                    number /= 10;
                }
                this.numbers.put(i, good && change);
            }
            if (this.numbers.get(i)) {
                count++;
            }
        }
        return count;
    }
}