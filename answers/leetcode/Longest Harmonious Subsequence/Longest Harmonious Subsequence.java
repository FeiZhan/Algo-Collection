class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        int longest = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (map.containsKey(entry.getKey() + 1)) {
                longest = Math.max(longest, entry.getValue() + map.get(entry.getKey() + 1));
            }
        }
        return longest;
    }
}