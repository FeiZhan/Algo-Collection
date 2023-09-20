class Solution {
    public boolean canBeEqual(String s1, String s2) {
        if (s1 == null || s2 == null) {
            return s1 == null && s2 == null;
        } else if (s1.length() != s2.length()) {
            return false;
        }

        int length = s1.length();
        Map<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < length; i += 2) {
            char c = s1.charAt(i);
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }
        for (int i = 0; i < length; i += 2) {
            char c = s2.charAt(i);
            if (!counts.containsKey(c)) {
                return false;
            }
            counts.put(c, counts.get(c) - 1);
            if (counts.get(c) <= 0) {
                counts.remove(c);
            }
        }
        if (!counts.isEmpty()) {
            return false;
        }

        for (int i = 1; i < length; i += 2) {
            char c = s1.charAt(i);
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }
        for (int i = 1; i < length; i += 2) {
            char c = s2.charAt(i);
            if (!counts.containsKey(c)) {
                return false;
            }
            counts.put(c, counts.get(c) - 1);
            if (counts.get(c) <= 0) {
                counts.remove(c);
            }
        }
        return counts.isEmpty();
    }
}