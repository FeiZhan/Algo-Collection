class Solution {
    public int countEven(int num) {
        int result = 0;
        for (int i = 1; i <= num; i++) {
            int current = i;
            int sum = 0;
            while (current > 0) {
                sum += current % 10;
                current /= 10;
            }
            if (sum % 2 == 0) {
                result++;
            }
        }

        return result;
    }
}
//Runtime: 2 ms, faster than 75.00% of Java online submissions for Count Integers With Even Digit Sum.
//Memory Usage: 40.1 MB, less than 75.00% of Java online submissions for Count Integers With Even Digit Sum.
