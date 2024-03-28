class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums) {
            numberSet.add(number);
        }

        int left = 0;
        int result = 0;
        Map<Integer, Integer> subMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            subMap.put(number, subMap.getOrDefault(number, 0) + 1);
            if (subMap.size() == numberSet.size()) {
                while (subMap.get(nums[left]) > 1) {
                    int leftNumber = nums[left];
                    subMap.put(leftNumber, subMap.get(leftNumber) - 1);
                    left++;
                }
                result += left + 1;
            }
        }

        return result;
    }
}