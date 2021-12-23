class Solution {
    public List<String> stringMatching(String[] words) {
        Arrays.sort(words, (w0, w1) -> w0.length() - w1.length());
        List<String> result = new LinkedList<>();

        for (int i = 0; i < words.length; i++) {
            String word0 = words[i];
            for (int j = i + 1; j < words.length; j++) {
                String word1 = words[j];
                if (word1.indexOf(word0) >= 0) {
                    result.add(word0);
                    break;
                }
            }
        }

        return result;
    }
}
//Runtime: 5 ms, faster than 32.56% of Java online submissions for String Matching in an Array.
//Memory Usage: 39.3 MB, less than 51.73% of Java online submissions for String Matching in an Array.
