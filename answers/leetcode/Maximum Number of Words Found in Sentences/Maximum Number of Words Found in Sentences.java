class Solution {
    public int mostWordsFound(String[] sentences) {
        int result = 0;

        for (String sentence : sentences) {
            int count = sentence.length() > 0 ? 1 : 0;
            for (char c : sentence.toCharArray()) {
                if (c == ' ') {
                    count++;
                }
            }
            result = Math.max(result, count);
        }

        return result;
    }
}
//Runtime: 6 ms, faster than 39.15% of Java online submissions for Maximum Number of Words Found in Sentences.
//Memory Usage: 40.8 MB, less than 44.43% of Java online submissions for Maximum Number of Words Found in Sentences.
