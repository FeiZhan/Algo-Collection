class Solution {
    public int maxVowels(String s, int k) {
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if ("aeiou".indexOf(s.charAt(i)) >= 0) {
                count++;
            }
            if (i >= k && "aeiou".indexOf(s.charAt(i - k)) >= 0) {
                count--;
            }
            if (i >= k - 1) {
                maxCount = Math.max(maxCount, count);
            }
        }
        return maxCount;
    }
}