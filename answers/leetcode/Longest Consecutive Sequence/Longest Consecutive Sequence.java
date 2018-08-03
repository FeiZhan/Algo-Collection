class Solution {
    public int longestConsecutive(int[] nums) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int num : nums) {
            numMap.put(num, -1);
        }
        int maxLength = 0;
        for (int num : numMap.keySet()) {
            if (numMap.get(num) == -1) {
                this.dfs(num, numMap);
                maxLength = Math.max(maxLength, numMap.get(num));
            }
        }
        return maxLength;
    }
    
    private int dfs(int num, Map<Integer, Integer> numMap) {
        if (numMap.containsKey(num)) {
            if (numMap.get(num) == -1) {
                int next = this.dfs(num + 1, numMap);
                numMap.put(num, next + 1);
            }
            return numMap.get(num);
        }
        return 0;
    }
}