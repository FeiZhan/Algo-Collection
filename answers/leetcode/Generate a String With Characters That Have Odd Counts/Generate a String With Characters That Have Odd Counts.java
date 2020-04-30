class Solution {
    public String generateTheString(int n) {
        return "a".repeat(n - (n % 2 == 1 ? 0 : 1)) + (n % 2 == 1 ? "" : "b");
    }
}