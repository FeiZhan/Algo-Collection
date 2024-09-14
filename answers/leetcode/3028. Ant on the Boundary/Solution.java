class Solution {
    public int returnToBoundaryCount(int[] nums) {
        int position = 0;
        int result = 0;
        for (int number : nums) {
            position += number;
            result += position == 0 ? 1 : 0;
        }

        return result;
    }
}