class Solution {
    public int minOperations(String s) {
        return Math.min(this.countOperations(s, false), this.countOperations(s, true));
    }

    private int countOperations(String s, boolean isOne) {
        int count = 0;
        for (char c : s.toCharArray()) {
            count += (isOne && c == '0') || (!isOne && c == '1') ? 1 : 0;
            isOne = !isOne;
        }
        return count;
    }
}