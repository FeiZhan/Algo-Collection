class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        Map<Integer, Integer> oldSum = new HashMap<>();
        oldSum.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            Map<Integer, Integer> newSum = new HashMap<>();
            for (int num : oldSum.keySet()) {
                int newNum = num + nums[i];
                newSum.put(newNum, newSum.getOrDefault(newNum, 0) + oldSum.get(num));
                newNum = num - nums[i];
                newSum.put(newNum, newSum.getOrDefault(newNum, 0) + oldSum.get(num));
            }
            oldSum = newSum;
        }
        return oldSum.getOrDefault(S, 0);
    }
}