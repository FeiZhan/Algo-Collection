class Solution {
    public String reverseStr(String s, int k) {
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i += 2 * k) {
            int length = i + k <= chars.length ? k : chars.length - i;
            for (int j = 0; j * 2 < length; j++) {
                char temp = chars[i + j];
                chars[i + j] = chars[i + length - j - 1];
                chars[i + length - j - 1] = temp;
            }
        }
        return new String(chars);
    }
}