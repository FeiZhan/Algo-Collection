class Solution {
    public int[] shortestToChar(String S, char C) {
        int[] distances = new int[S.length()];
        int left = -1;
        int right = -1;
        for (int i = 0; i < S.length(); i++) {
            if (i >= right) {
                left = right;
                for (right = i; right < S.length() && S.charAt(right) != C; right++) {
                }
            }
            distances[i] = Integer.MAX_VALUE;
            if (left >= 0) {
                distances[i] = Math.min(distances[i], i - left);
            }
            if (right >= 0 && right < S.length()) {
                distances[i] = Math.min(distances[i], right - i);
            }
        }
        return distances;
    }
}