class Solution {
    public int missingInteger(int[] nums) {
        int sum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] + 1 != nums[i]) {
                break;
            }
            sum += nums[i];
        }

        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums) {
            numberSet.add(number);
        }
        while (numberSet.contains(sum)) {
            sum++;
        }

        return sum;
    }
}