class Solution {
    public String toGoatLatin(String S) {
        String[] words = S.split(" ");
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            if (i > 0) {
                result.append(" ");
            }
            String word = words[i];
            if (word.length() > 0) {
                char c = Character.toLowerCase(word.charAt(0));
                if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                    result.append(word.substring(1));
                    result.append(word.charAt(0));
                } else {
                    result.append(word);
                }
                result.append("ma");
                for (int j = 0; j <= i; j++) {
                    result.append("a");
                }
            }
        }
        return result.toString();
    }
}