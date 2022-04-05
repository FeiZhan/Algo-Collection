class Solution {
    public long numberOfWays(String s) {
        int length = s.length();
        int[] left = new int[2];
        int[] right = new int[2];
        int[][] leftCount = new int[2][length];
        int[][] rightCount = new int[2][length];

        for (int i = 0; i < length; i++) {
            int leftDigit = Character.getNumericValue(s.charAt(i));
            left[leftDigit]++;
            leftCount[0][i] = left[0];
            leftCount[1][i] = left[1];

            int rightIndex = length - i - 1;
            int rightDigit = Character.getNumericValue(s.charAt(rightIndex));
            right[rightDigit]++;
            rightCount[0][rightIndex] = right[0];
            rightCount[1][rightIndex] = right[1];
        }

        long result = 0l;
        for (int i = 1; i + 1 < length; i++) {
            char c = s.charAt(i);
            int flip = c == '0' ? 1 : 0;
            result += leftCount[flip][i - 1] * rightCount[flip][i + 1];
            System.out.println(i + " " + c + " : " + leftCount[flip][i - 1] + " " + rightCount[flip][i + 1] + " = " + result);
        }

        return result;
    }
}
//Runtime: 199 ms, faster than 21.94% of Java online submissions for Number of Ways to Select Buildings.
//Memory Usage: 98.3 MB, less than 40.40% of Java online submissions for Number of Ways to Select Buildings.
