class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums) {
            numberSet.add(number);
        }
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            if (!numberSet.contains(number)) {
                continue;
            }
            numberSet.remove(number);
            int length = 1;
            int index = 1;
            while (numberSet.contains(number - index)) {
                numberSet.remove(number - index);
                index++;
            }
            length += index - 1;
            index = 1;
            while (numberSet.contains(number + index)) {
                numberSet.remove(number + index);
                index++;
            }
            length += index - 1;
            result = Math.max(result, length);
        }

        return result;
    }
}