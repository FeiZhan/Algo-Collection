class Solution {
    public int findClosestNumber(int[] nums) {
        int result = Integer.MAX_VALUE;

        for (int number : nums) {
            int absResult = Math.abs(result);
            int absNumber = Math.abs(number);
            if (absResult > absNumber || (absResult == absNumber && number > result)) {
                result = number;
            }
        }

        return result;
    }
}
//Runtime: 2 ms, faster than 78.24% of Java online submissions for Find Closest Number to Zero.
//Memory Usage: 52 MB, less than 11.09% of Java online submissions for Find Closest Number to Zero.
