class Solution {
    public int findNonMinOrMax(int[] nums) {
        int max = 0;
        int min = Integer.MAX_VALUE;
        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums) {
            max = Math.max(max, number);
            min = Math.min(min, number);
            numberSet.add(number);
        }
        for (int number : numberSet) {
            if (number != max && number != min) {
                return number;
            }
        }

        return -1;
    }
}