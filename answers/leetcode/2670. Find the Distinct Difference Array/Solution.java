class Solution {
    public int[] distinctDifferenceArray(int[] nums) {
        Map<Integer, Integer> suffix = new HashMap<>();
        for (int number : nums) {
            suffix.put(number, suffix.getOrDefault(number, 0) + 1);
        }
        Set<Integer> prefix = new HashSet<>();
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            suffix.put(number, suffix.get(number) - 1);
            if (suffix.get(number) == 0) {
                suffix.remove(number);
            }
            prefix.add(number);
            result[i] = prefix.size() - suffix.size();
        }

        return result;
    }
}