class Solution {
    public boolean canConstruct(String s, int k) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : s.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }
        int oddCount = 0;
        for (int value : counts.values()) {
            oddCount += value % 2;
        }
        return k >= oddCount && k <= s.length();
    }
}