class Solution {
    public int mostFrequent(int[] nums, int key) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] == key) {
                counts.put(nums[i], counts.getOrDefault(nums[i], 0) + 1);
            }
        }

        int max = 0;
        int result = 0;
        for (int number : counts.keySet()) {
            int count = counts.get(number);
            if (count > max) {
                max = count;
                result = number;
            }
        }

        return result;
    }
}
//Runtime: 5 ms, faster than 38.47% of Java online submissions for Most Frequent Number Following Key In an Array.
//Memory Usage: 46.7 MB, less than 38.77% of Java online submissions for Most Frequent Number Following Key In an Array.
