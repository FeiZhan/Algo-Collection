class Solution {
    public boolean checkInclusion(String s1, String s2) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (char c : s1.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }
        int left = 0;
        int right = 0;
        while (right < s2.length()) {
            char c = s2.charAt(right);
            if (charMap.containsKey(c)) {
                int count = charMap.get(c) - 1;
                if (count == 0) {
                    charMap.remove(c);
                } else {
                    charMap.put(c, count);
                }
                right++;
            } else {
                if (left < right) {
                    charMap.put(s2.charAt(left), charMap.getOrDefault(s2.charAt(left), 0) + 1);
                }
                left++;
                right = Math.max(right, left);
            }
            if (charMap.size() == 0) {
                return true;
            }
        }
        return false;
    }
}