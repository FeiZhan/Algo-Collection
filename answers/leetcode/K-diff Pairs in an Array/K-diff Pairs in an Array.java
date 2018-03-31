class Solution {
    public int findPairs(int[] nums, int k) {
        Map<Integer, Integer> numMap = new HashMap<Integer, Integer>();
        for (int num : nums) {
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }
        int pairNum = 0;
        for (int num : numMap.keySet()) {
            if ((0 == k && numMap.get(num) > 1) || (k > 0 && numMap.containsKey(num + k))) {
                pairNum++;
            }
        }
        return pairNum;
    }
}