class Solution {
    public boolean hasAllCodes(String s, int k) {
        int count = 1;
        for (int i = 0; i < k; i++) {
            count *= 2;
        }
        Set<String> numbers = new HashSet<>();
        for (int i = k - 1; i < s.length(); i++) {
            String substring = s.substring(i - k + 1, i + 1);
            numbers.add(substring);
        }
        return count == numbers.size();
    }
}