class Solution {
    public int numberOfSubstrings(String s) {
        int left = 0;
        int result = 0;
        Map<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            counts.put(c, counts.getOrDefault(c, 0) + 1);
            while (counts.size() >= 3 && left < i) {
                char c1 = s.charAt(left);
                counts.put(c1, counts.getOrDefault(c1, 0) - 1);
                if (counts.get(c1) <= 0) {
                    counts.remove(c1);
                }
                left++;
            }
            result += left;
        }
        return result;
    }
}