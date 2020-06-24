import java.util.SortedMap;

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        int left = 0;
        int longest = 0;
        SortedMap<Integer, Integer> numMap = new TreeMap<>();
        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            numMap.put(number, numMap.getOrDefault(number, 0) + 1);
            int difference = numMap.lastKey() - numMap.firstKey();
            while (left < i && difference > limit) {
                int leftNumber = nums[left];
                numMap.put(leftNumber, numMap.get(leftNumber) - 1);
                if (numMap.get(leftNumber) <= 0) {
                    numMap.remove(leftNumber);
                }
                left++;
                difference = numMap.lastKey() - numMap.firstKey();
            }
            if (difference <= limit) {
                longest = Math.max(longest, i - left + 1);
            }
        }
        return longest;
    }
}