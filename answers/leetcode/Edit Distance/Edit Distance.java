class Solution {
    public int minDistance(String word1, String word2) {
        int[][] distances = new int[word1.length() + 1][word2.length() + 1];
        for (int i = 0; i <= word1.length(); i++) {
            for (int j = 0; j <= word2.length(); j++) {
                int distance = 0;
                if (i == 0 || j == 0) {
                    distance = i + j;
                } else {
                    distance = distances[i - 1][j - 1] + (word1.charAt(i - 1) == word2.charAt(j - 1) ? 0 : 1);
                    distance = Math.min(distance, distances[i - 1][j] + 1);
                    distance = Math.min(distance, distances[i][j - 1] + 1);
                }
                distances[i][j] = distance;
            }
        }
        return distances[word1.length()][word2.length()];
    }
}