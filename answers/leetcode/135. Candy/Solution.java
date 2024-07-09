class Solution {
    public int candy(int[] ratings) {
        int length = ratings.length;
        int[] candies = new int[length];
        candies[0] = 1;
        for (int i = 1; i < length; i++) {
            candies[i] = 1;
            if (ratings[i - 1] < ratings[i]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
        }

        int result = 0;
        for (int i = 0; i < length; i++) {
            result += candies[i];
        }

        return result;
    }
}