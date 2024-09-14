class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        int result = 0;
        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums) {
            if (numberSet.contains(number)) {
                result ^= number;
            } else {
                numberSet.add(number);
            }
        }

        return result;
    }
}