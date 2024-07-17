import java.util.SortedMap;

class Solution {
    public int maxResult(int[] nums, int k) {
        int length = nums.length;
        Map<Integer, Integer> indexMap = new HashMap<>();
        indexMap.put(0, nums[0]);
        SortedMap<Integer, Integer> sumMap = new TreeMap<>();
        sumMap.put(nums[0], 1);
        int left = 0;

        for (int i = 1; i < length; i++) {
            if (i - left > k) {
                int leftValue = indexMap.get(left);
                indexMap.remove(left);
                sumMap.put(leftValue, sumMap.get(leftValue) - 1);
                if (sumMap.get(leftValue) == 0) {
                    sumMap.remove(leftValue);
                }
                left++;
            }
            int sum = nums[i] + sumMap.lastKey();
            indexMap.put(i, sum);
            sumMap.put(sum, sumMap.getOrDefault(sum, 0) + 1);
        }

        return indexMap.get(length - 1);
    }
}