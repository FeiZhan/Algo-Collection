class Solution {
    public int countPrefixes(String[] words, String s) {
        int result = 0;
        for (String word : words) {
            if (s.startsWith(word)) {
                result++;
            }
        }

        return result;
    }
}
//Runtime: 1 ms, faster than 95.91% of Java online submissions for Count Prefixes of a Given String.
//Memory Usage: 44.1 MB, less than 51.68% of Java online submissions for Count Prefixes of a Given String.
