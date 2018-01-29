class Solution {
    public int compress(char[] chars) {
        int count = 1;
        int start = 0;
        for (int i = 1; i <= chars.length; i++) {
            if (i != chars.length && chars[i] == chars[i - 1]) {
                count++;
            } else {
                chars[start] = chars[i - 1];
                start++;
                if (count > 1) {
                    char[] num = String.valueOf(count).toCharArray();
                    for (char digit : num) {
                        chars[start] = digit;
                        start++;
                    }
                }
                count = 1;
            }
        }
        return start;
    }
}