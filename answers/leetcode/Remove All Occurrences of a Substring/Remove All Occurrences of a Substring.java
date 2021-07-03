class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder sb = new StringBuilder(s);

        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (c == part.charAt(0) && i + part.length() <= sb.length()) {
                String substring = sb.substring(i, i + part.length());
                if (substring.equals(part)) {
                    sb.delete(i, i + part.length());
                    i = Math.max(i - part.length(), -1);
                }
            }
        }

        return sb.toString();
    }
}