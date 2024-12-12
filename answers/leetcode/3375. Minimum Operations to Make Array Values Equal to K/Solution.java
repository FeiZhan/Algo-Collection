class Solution {
    public int minOperations(int[] nums, int k) {
        boolean isSmaller = false;
        Set<Integer> numbers = new HashSet<>();
        for (int number : nums) {
            if (number > k) {
                numbers.add(number);
            } else if (number < k) {
                isSmaller = true;
            }
        }

        return isSmaller ? -1 : numbers.size();
    }
}