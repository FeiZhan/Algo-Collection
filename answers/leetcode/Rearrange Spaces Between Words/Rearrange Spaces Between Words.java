class Solution {
    public String reorderSpaces(String text) {
        List<String> words = new LinkedList<>();
        int left = 0;
        int length = 0;
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (c == ' ') {
                if (i > left) {
                    length += i - left;
                    String word = text.substring(left, i);
                    words.add(word);
                }
                left = i + 1;
            }
        }
        if (left < text.length()) {
            words.add(text.substring(left));
            length += text.length() - left;
        }
        int spaces = text.length() - length;
        StringBuilder sb = new StringBuilder();
        if (words.size() == 1) {
            sb.append(words.get(0));
            while (sb.length() < text.length()) {
                sb.append(' ');
            }
            return sb.toString();
        }
        int space = spaces / (words.size() - 1);
        int trailing = spaces % (words.size() - 1);
        for (int i = 0; i < words.size(); i++) {
            sb.append(words.get(i));
            if (i + 1 < words.size()) {
                for (int j = 0; j < space; j++) {
                    sb.append(' ');
                }
            }
        }
        for (int i = 0; i < trailing; i++) {
            sb.append(' ');
        }
        return sb.toString();
    }
}