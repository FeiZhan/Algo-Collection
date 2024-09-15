class Solution {
    public String stringHash(String s, int k) {
        int length = s.length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i += k) {
            String substring = s.substring(i, i + k);
            int sum = 0;
            for (char c : substring.toCharArray()) {
                sum += (int)(c - 'a');
            }
            sb.append((char)('a' + (sum % 26)));
        }

        return sb.toString();
    }
}