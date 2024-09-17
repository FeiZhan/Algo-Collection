class Solution {
    public int minimumDeletions(String s) {
        int bCount = 0;
        for (char c : s.toCharArray()) {
            bCount += c == 'b' ? 1 : 0;
        }
        int count = 0;
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < s.length(); i++) {
            int b = s.charAt(i) == 'b' ? 1 : 0;
            result = Math.min(result, count + s.length() - i - 1 - bCount + count + b);
            count += b;
        }

        return result;
    }
}