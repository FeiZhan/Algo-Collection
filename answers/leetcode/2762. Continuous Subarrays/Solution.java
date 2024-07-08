import java.util.SortedMap;

class Solution {
    public long continuousSubarrays(int[] nums) {
        int length = nums.length;
        int left = 0;
        long result = 0l;
        SortedMap<Integer, Integer> numberMap = new TreeMap<>();

        for (int i = 0; i < length; i++) {
            int number = nums[i];
            numberMap.put(number, numberMap.getOrDefault(number, 0) + 1);
            while (left < i && numberMap.lastKey() - numberMap.firstKey() > 2) {
                int leftNumber = nums[left];
                numberMap.put(leftNumber, numberMap.get(leftNumber) - 1);
                if (numberMap.get(leftNumber) == 0) {
                    numberMap.remove(leftNumber);
                }
                result += (long)(i - left);
                left++;
            }
        }

        return result + (long)(length - left + 1) * (long)(length - left) / 2l;
    }
}