class Solution {
    public int findFinalValue(int[] nums, int original) {
        Set<Integer> numbers = new HashSet<>();
        for (int number : nums) {
            numbers.add(number);
        }
        while (numbers.contains(original)) {
            original *= 2;
        }

        return original;
    }
}
//Runtime: 4 ms, faster than 69.29% of Java online submissions for Keep Multiplying Found Values by Two.
//Memory Usage: 45.2 MB, less than 42.38% of Java online submissions for Keep Multiplying Found Values by Two.
