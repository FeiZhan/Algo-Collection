class Solution {
    public int prefixCount(String[] words, String pref) {
        int count = 0;
        for (String word : words) {
            int length = Math.min(word.length(), pref.length());
            if (word.substring(0, length).equals(pref)) {
                count++;
            }
        }

        return count;
    }
}
//Runtime: 2 ms, faster than 33.33% of Java online submissions for Counting Words With a Given Prefix.
//Memory Usage: 42.9 MB, less than 83.33% of Java online submissions for Counting Words With a Given Prefix.
