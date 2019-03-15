class Solution {
    public String maskPII(String S) {
        if (S == null) {
            return null;
        }
        int atIndex = S.indexOf('@');
        StringBuilder sb = new StringBuilder();
        if (atIndex >= 0) {
            if (atIndex < 2) {
                sb.append(S);
            } else {
                sb.append(Character.toLowerCase(S.charAt(0)))
                    .append("*****")
                    .append(Character.toLowerCase(S.charAt(atIndex - 1)))
                    .append(S.substring(atIndex).toLowerCase());
            }
        } else {
            for (char c : S.toCharArray()) {
                if (Character.isDigit(c)) {
                    sb.append(c);
                }
            }
            for (int i = 0; i + 4 < sb.length(); i++) {
                sb.setCharAt(i, '*');
            }
            if (sb.length() > 10) {
                sb.insert(0, '+');
                sb.insert(sb.length() - 10, '-');
            }
            sb.insert(sb.length() - 7, '-');
            sb.insert(sb.length() - 4, '-');
        }
        return sb.toString();
    }
}