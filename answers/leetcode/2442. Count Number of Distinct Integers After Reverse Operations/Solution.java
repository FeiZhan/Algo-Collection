class Solution {
    public int countDistinctIntegers(int[] nums) {
        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums) {
            numberSet.add(number);
            int reversed = 0;
            while (number > 0) {
                reversed = reversed * 10 + number % 10;
                number /= 10;
            }
            numberSet.add(reversed);
        }

        return numberSet.size();
    }
}