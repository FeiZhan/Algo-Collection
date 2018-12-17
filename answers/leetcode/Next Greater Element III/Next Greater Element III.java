class Solution {
    public int nextGreaterElement(int n) {
        List<Integer> digits = new ArrayList<>();
        while (n > 0) {
            digits.add(n % 10);
            n /= 10;
        }

        int greatestIndex = 0;
        int leftIndex = -1;
        for (int i = 0; i < digits.size(); i++) {
            if (digits.get(i) >= digits.get(greatestIndex)) {
                greatestIndex = i;
            } else {
                leftIndex = i;
                break;
            }
        }
        if (leftIndex < 0) {
            return -1;
        }

        int rightIndex = greatestIndex;
        for (int i = 0; i < leftIndex; i++) {
            if (digits.get(i) > digits.get(leftIndex) && digits.get(i) < digits.get(rightIndex)) {
                rightIndex = i;
            }
        }
        //System.out.println(leftIndex + " " + rightIndex);
        int temp = digits.get(leftIndex);
        digits.set(leftIndex, digits.get(rightIndex));
        digits.set(rightIndex, temp);
        Collections.sort(digits.subList(0, leftIndex), Collections.reverseOrder());

        long next = 0l;
        for (int i = digits.size() - 1; i >= 0; i--) {
            next = next * 10 + (long) digits.get(i);
            //System.out.println(i + " " + digits.get(i) + " " + next);
            if (next > (long) Integer.MAX_VALUE) {
                return -1;
            }
        }
        return (int) next;
    }
}