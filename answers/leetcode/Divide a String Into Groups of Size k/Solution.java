class Solution {
    public String[] divideString(String s, int k, char fill) {
        int length = (s.length() + k - 1) / k;
        String[] result = new String[length];

        for (int i = 0; i < length; i++) {
            if (i * k + k <=  s.length()) {
                result[i] = s.substring(i * k, i * k + k);
            } else {
                char[] repeat = new char[i * k + k - s.length()];
                Arrays.fill(repeat, fill);
                result[i] = s.substring(i * k) + new String(repeat);
            }
        }

        return result;
    }
}
//Runtime: 1 ms, faster than 98.70% of Java online submissions for Divide a String Into Groups of Size k.
//Memory Usage: 42.8 MB, less than 5.68% of Java online submissions for Divide a String Into Groups of Size k.
