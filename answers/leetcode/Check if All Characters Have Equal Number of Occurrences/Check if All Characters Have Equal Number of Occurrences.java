class Solution {
    public boolean areOccurrencesEqual(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        int count = map.values().iterator().next();
        for (int value : map.values()) {
            if (count != value) {
                return false;
            }
        }

        return true;
    }
}