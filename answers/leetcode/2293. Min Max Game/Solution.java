class Solution {
    public int minMaxGame(int[] nums) {
        int length = nums.length;

        while (length > 1) {
            for (int i = 1; i < length; i++) {
                nums[i / 2] = i / 2 % 2 == 0
                    ? Math.min(nums[i - 1], nums[i])
                    : Math.max(nums[i - 1], nums[i]);
            }
            length /= 2;
        }

        return nums[0];
    }
}
//Runtime: 2 ms, faster than 75.00% of Java online submissions for Min Max Game.
//Memory Usage: 44.7 MB, less than 25.00% of Java online submissions for Min Max Game.
