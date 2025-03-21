class Solution {
    public int maxNonOverlapping(int[] nums, int target) {
        int sum = 0;
        int result = 0;
        int[] dp = new int[nums.length];
        Map<Integer, List<Integer>> sumMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (sum == target) {
                dp[i] = Math.max(dp[i], 1);
            }
            for (int previous : sumMap.getOrDefault(sum - target, Collections.emptyList())) {
                dp[i] = Math.max(dp[i], dp[previous] + 1);
            }
            List<Integer> list = sumMap.getOrDefault(sum, new LinkedList<>());
            list.add(i);
            sumMap.put(sum, list);
            dp[i] = Math.max(result, dp[i]);
            result = Math.max(result, dp[i]);
        }

        return result;
    }
}