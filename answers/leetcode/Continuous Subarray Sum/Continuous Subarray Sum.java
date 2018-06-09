class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> numMap = new HashMap<>();
        numMap.put(0, -1);
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (numMap.containsKey(mod)) {
                if (numMap.get(mod) + 1 < i) {
                    return true;
                }
            } else {
                numMap.put(mod, i);
            }
        }
        return false;
    }
}