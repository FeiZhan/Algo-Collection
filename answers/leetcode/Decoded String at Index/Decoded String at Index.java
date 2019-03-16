class Solution {
    public String decodeAtIndex(String S, int K) {
        if (S == null || K <= 0) {
            return null;
        }
        return Character.toString(this.decodeAtIndex(S, S.length() - 1, (long)(K - 1)));
    }

    private char decodeAtIndex(String str, int length, long target) {
        System.out.println(length + " " + str.substring(0, length + 1) + " " + target);
        long count = 0l;
        for (int i = 0; i <= length; i++) {
            char c = str.charAt(i);
            if (Character.isDigit(c)) {
                int digit = Character.getNumericValue(c);
                count *= digit;
                if (count >= target + 1) {
                    return this.decodeAtIndex(str, i - 1, target % (count / digit));
                }
            } else {
                count++;
                if (count >= target + 1) {
                    return str.charAt(i);
                }
            }
        }
        return ' ';
    }
}