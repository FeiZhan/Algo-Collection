class Solution {
    public int countOperations(int num1, int num2) {
        int result = 0;

        while (num1 != 0 && num2 != 0) {
            int temp = num1;
            num1 = Math.min(num1, num2);
            num2 = Math.max(temp, num2);
            result += num2 / num1;
            num2 %= num1;
        }

        return result;
    }
}
//Runtime: 1 ms, faster than 91.32% of Java online submissions for Count Operations to Obtain Zero.
//Memory Usage: 40.6 MB, less than 81.40% of Java online submissions for Count Operations to Obtain Zero.
