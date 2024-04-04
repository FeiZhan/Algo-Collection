class Solution {
    public int maxConsecutiveAnswers(String answerKey, int k) {
        return Math.max(this.run('T', answerKey, k), this.run('F', answerKey, k));
    }

    private int run(char normal, String answer, int k) {
        int count = 0;
        int left = 0;
        int result = 0;
        for (int i = 0; i < answer.length(); i++) {
            char c = answer.charAt(i);
            if (c != normal) {
                count++;
            }
            while (count > k) {
                char c1 = answer.charAt(left);
                if (c1 != normal) {
                    count--;
                }
                left++;
            }
            result = Math.max(result, i - left + 1);
        }

        return result;
    }
}