class Solution {
    public int secondsToRemoveOccurrences(String s) {
        boolean flag = true;
        int result = 0;
        StringBuilder sb = new StringBuilder(s);
        while (flag) {
            flag = false;
            for (int i = 1; i < s.length(); i++) {
                if (sb.charAt(i - 1) == '0' && sb.charAt(i) == '1') {
                    sb.setCharAt(i - 1, '1');
                    sb.setCharAt(i, '0');
                    flag = true;
                    i++;
                }
            }
            if (flag) {
                result++;
            }
        }

        return result;
    }
}