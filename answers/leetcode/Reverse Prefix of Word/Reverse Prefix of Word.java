class Solution {
    public String reversePrefix(String word, char ch) {
        int index = word.indexOf(ch);
        if (index < 0) {
            return word;
        }

        int middle = index / 2;
        StringBuilder sb = new StringBuilder(word);
        for (int i = 0; i <= middle; i++) {
            char c = sb.charAt(i);
            sb.setCharAt(i, sb.charAt(index - i));
            sb.setCharAt(index - i, c);
        }

        return sb.toString();
    }
}