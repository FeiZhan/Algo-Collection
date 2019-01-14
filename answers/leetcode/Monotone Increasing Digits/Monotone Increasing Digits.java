class Solution {
    public int monotoneIncreasingDigits(int N) {
        int temp = N;
        List<Integer> digits = new ArrayList<>();
        while (temp > 0) {
            digits.add(0, temp % 10);
            temp /= 10;
        }
        int decreaseIndex = -1;
        for (int i = 1; i < digits.size(); i++) {
            if (digits.get(i) < digits.get(i - 1)) {
                decreaseIndex = i;
                break;
            }
        }
        if (decreaseIndex == -1) {
            return N;
        } else {
            int startIndex = 0;
            int startNum = digits.get(decreaseIndex - 1);
            for (int i = decreaseIndex - 1; i >= 0; i--) {
                if (digits.get(i) != startNum) {
                    startIndex = i + 1;
                    break;
                }
            }
            digits.set(startIndex, digits.get(startIndex) - 1);
            for (int i = startIndex + 1; i < digits.size(); i++) {
                digits.set(i, 9);
            }
        }
        int result = 0;
        for (int i = 0; i < digits.size(); i++) {
            result = result * 10 + digits.get(i);
        }
        return result;
    }
}