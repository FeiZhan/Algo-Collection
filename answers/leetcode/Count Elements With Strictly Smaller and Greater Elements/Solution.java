class Solution {
    public int countElements(int[] nums) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        Map<Integer, Integer> numbers = new HashMap<>();
        for (int number : nums) {
            max = Math.max(max, number);
            min = Math.min(min, number);
            numbers.put(number, numbers.getOrDefault(number, 0) + 1);
        }

        return max != min ? nums.length - numbers.get(max) - numbers.get(min) : 0;
    }
}
//Runtime: 1 ms, faster than 50.00% of Java online submissions for Count Elements With Strictly Smaller and Greater Elements .
//Memory Usage: 38.5 MB, less than 12.50% of Java online submissions for Count Elements With Strictly Smaller and Greater Elements .
