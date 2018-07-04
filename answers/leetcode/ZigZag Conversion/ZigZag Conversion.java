class Solution {
    public String convert(String s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; i + j < s.length(); j += numRows * 2 - 2) {
                sb.append(s.charAt(i + j));
                if (i > 0 && i + 1 < numRows && j + numRows * 2 - 2 - i < s.length()) {
                    sb.append(s.charAt(j + numRows * 2 - 2 - i));
                }
            }
        }
        return sb.toString();
    }
}