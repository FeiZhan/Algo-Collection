class Solution {
    public int largestInteger(int num) {
        List<Integer> digits = new LinkedList<>();
        while (num > 0) {
            digits.add(0, num % 10);
            num /= 10;
        }

        List<Integer> even = new ArrayList<>();
        List<Integer> odd = new ArrayList<>();
        for (int digit : digits) {
            if (digit % 2 == 0) {
                even.add(digit);
            } else {
                odd.add(digit);
            }
        }
        Collections.sort(even, Collections.reverseOrder());
        Collections.sort(odd, Collections.reverseOrder());

        int evenIndex = 0;
        int oddIndex = 0;
        int result = 0;
        for (int digit : digits) {
            int swapped = 0;
            if (digit % 2 == 0) {
                swapped = even.get(evenIndex);
                evenIndex++;
            } else {
                swapped = odd.get(oddIndex);
                oddIndex++;
            }
            result = result * 10 + swapped;
        }

        return result;
    }
}
//Runtime: 2 ms, faster than 82.21% of Java online submissions for Largest Number After Digit Swaps by Parity.
//Memory Usage: 39.4 MB, less than 90.10% of Java online submissions for Largest Number After Digit Swaps by Parity.
