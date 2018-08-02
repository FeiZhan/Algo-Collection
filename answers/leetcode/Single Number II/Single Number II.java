class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int num : nums) {
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }
        for (Map.Entry<Integer, Integer> entry : numMap.entrySet()) {
            if (entry.getValue() != 3) {
                return entry.getKey();
            }
        }
        return -1;
    }
}