class Solution {
    public int minSteps(String s, String t) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : s.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }
        for (char c : t.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) - 1);
        }
        int count = 0;
        for (int value : counts.values()) {
            count += Math.abs(value);
        }
        return count / 2;
    }
}