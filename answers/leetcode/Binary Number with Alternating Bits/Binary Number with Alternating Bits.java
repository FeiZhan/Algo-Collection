class Solution {
    public boolean hasAlternatingBits(int n) {
        boolean previous = false;
        boolean first = true;
        while (n != 0) {
            boolean current = n % 2 == 1;
            if (!first && current == previous) {
                return false;
            }
            first = false;
            previous = current;
            n /= 2;
        }
        return true;
    }
}