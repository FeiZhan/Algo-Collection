class Solution {
    public boolean backspaceCompare(String S, String T) {
        return this.convert(S).equals(this.convert(T));
    }

    private String convert(String original) {
        StringBuilder sb = new StringBuilder();
        for (char c : original.toCharArray()) {
            if (c != '#') {
                sb.append(c);
            } else if (sb.length() > 0) {
                sb.deleteCharAt(sb.length() - 1);
            }
        }
        return sb.toString();
    }
}