class Solution {
    public int countValidWords(String sentence) {
        int count = 0;
        String[] split = sentence.split(" ");

        for (String word : split) {
            if (word == null || word.length() == 0 || word.matches(".*\\d.*")) {
                continue;
            }

            long hyphens = word.chars().filter(ch -> ch == '-').count();
            if (hyphens > 1) {
                continue;
            } else if (hyphens == 1) {
                int hyphen = word.indexOf("-");
                if (hyphen == 0 || hyphen  == word.length() - 1 || !Character.isAlphabetic(word.charAt(hyphen - 1)) || !Character.isAlphabetic(word.charAt(hyphen + 1))) {
                    continue;
                }
            }

            char last = word.charAt(word.length() - 1);
            long punctuations = word.chars().filter(ch -> ch == '!' || ch == '.' || ch == ',').count();
            if (punctuations > 1) {
                continue;
            } else if (punctuations == 0 || last == '!' || last == '.' || last == ',') {
                count++;
            }
        }

        return count;
    }
}
//Runtime: 45 ms, faster than 24.54% of Java online submissions for Number of Valid Words in a Sentence.
//Memory Usage: 54.5 MB, less than 12.27% of Java online submissions for Number of Valid Words in a Sentence.
