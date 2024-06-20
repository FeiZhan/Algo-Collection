class Solution {
    public long sumDigitDifferences(int[] nums) {
        long result = 0l;
        while (true) {
            boolean flag = true;
            Map<Integer, Long> counts = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != 0) {
                    flag = false;
                }
                int digit = nums[i] % 10;
                counts.put(digit, counts.getOrDefault(digit, 0l) + 1l);
                nums[i] /= 10;
            }
            if (flag) {
                break;
            }

            List<Integer> digits = new LinkedList<>(counts.keySet());
            for (int i = 0; i < digits.size(); i++) {
                for (int j = i + 1; j < digits.size(); j++) {
                    result += counts.get(digits.get(i)) * counts.get(digits.get(j));
                }
            }
        }

        return result;
    }
}