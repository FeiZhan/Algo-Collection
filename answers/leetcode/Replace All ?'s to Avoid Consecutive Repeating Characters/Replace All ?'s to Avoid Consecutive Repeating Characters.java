class Solution {
    public String modifyString(String s) {
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (c == '?') {
                char left = i > 0 ? sb.charAt(i - 1) : ' ';
                char right = i + 1 < sb.length() ? sb.charAt(i + 1) : ' ';
                for (char j = 'a'; j <= 'z'; j++) {
                    if (left != j && right != j) {
                        sb.setCharAt(i, j);
                        break;
                    }
                }
            }
        }
        return sb.toString();
    }
}