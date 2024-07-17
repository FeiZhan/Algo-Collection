class Solution {
    public int bestClosingTime(String customers) {
        int score = 0;
        int maxScore = 0;
        int result = -1;
        for (int i = 0; i < customers.length(); i++) {
            score += customers.charAt(i) == 'Y' ? 1 : -1;
            if (score > maxScore) {
                maxScore = score;
                result = i;
            }
        }

        return result + 1;
    }
}