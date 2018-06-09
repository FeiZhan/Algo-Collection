class Solution {
    public String findLongestWord(String s, List<String> d) {
        String longest = "";
        for (String word : d) {
            boolean smaller = false;
            if (word.length() == longest.length()) {
                for (int i = 0; i < word.length(); i++) {
                    if (word.charAt(i) != longest.charAt(i)) {
                        smaller = word.charAt(i) < longest.charAt(i);
                        break;
                    }
                }
            }
            if (word.length() > longest.length() || smaller) {
                int index = 0;
                for (int i = 0; i < s.length(); i++) {
                    if (word.charAt(index) == s.charAt(i)) {
                        index++;
                    }
                    if (index >= word.length()) {
                        break;
                    }
                }
                if (index == word.length()) {
                    longest = word;
                }
            }
        }
        return longest;
    }
}