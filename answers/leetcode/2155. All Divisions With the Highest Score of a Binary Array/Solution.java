class Solution {
    public List<Integer> maxScoreIndices(int[] nums) {
        int one = 0;
        for (int number : nums) {
            one += number;
        }

        int leftZero = 0;
        int maxScore = one;
        List<Integer> result = new LinkedList<>();
        result.add(0);

        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            if (number == 0) {
                leftZero++;
            } else {
                one--;
            }
            int score = leftZero + one;
            if (score > maxScore) {
                maxScore = score;
                result = new LinkedList<>();
            }
            if (score == maxScore) {
                result.add(i + 1);
            }
        }

        return result;
    }
}