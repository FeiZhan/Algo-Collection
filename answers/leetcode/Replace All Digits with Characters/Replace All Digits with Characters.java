class Solution {
    public String replaceDigits(String s) {
        StringBuilder sb = new StringBuilder(s);
        for (int i = 1; i < sb.length(); i += 2) {
            int c = sb.charAt(i - 1) + Character.getNumericValue(sb.charAt(i));
            sb.setCharAt(i, (char) c);
        }

        return sb.toString();
    }
}