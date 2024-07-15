class Solution {
    public int countPalindromicSubsequence(String s) {
        int length = s.length();
        Map<Character, Integer> leftMap = new HashMap<>();
        Map<Character, Integer> rightMap = new HashMap<>();
        for (int i = 0; i < length; i++) {
            char c = s.charAt(i);
            leftMap.putIfAbsent(c, i);
            rightMap.put(c, i);
        }

        int result = 0;
        for (char c : leftMap.keySet()) {
            int left = leftMap.get(c);
            int right = rightMap.get(c);
            Set<Character> charSet = new HashSet<>();
            for (int i = left + 1; i < right; i++) {
                charSet.add(s.charAt(i));
            }
            result += charSet.size();
        }

        return result;
    }
}