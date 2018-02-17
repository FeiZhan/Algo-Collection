class Solution {
    public boolean repeatedSubstringPattern(String s) {
        for (int i = 1; i * 2 <= s.length(); i++) {
            if (s.length() % i != 0) {
                continue;
            }
            String subString = s.substring(0, i);
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < s.length() / i; j++) {
                sb.append(subString);
            }
            if (sb.toString().equals(s)) {
                return true;
            }
        }
        return false;
    }
}