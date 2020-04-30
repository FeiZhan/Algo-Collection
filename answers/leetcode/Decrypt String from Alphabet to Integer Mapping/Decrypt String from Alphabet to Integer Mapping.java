class Solution {
    public String freqAlphabets(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            int number = -1;
            if (c == '#' && i >= 2) {
                number = Character.getNumericValue(s.charAt(i - 1)) + Character.getNumericValue(s.charAt(i - 2)) * 10;
                i -= 2;
            } else {
                number = Character.getNumericValue(s.charAt(i));
            }
            sb.insert(0, (char)(number - 1 + 'a'));
        }
        return sb.toString();
    }
}