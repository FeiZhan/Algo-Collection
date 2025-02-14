class Solution {
    public int numberOfSubstrings(String s, int k) {
        int left = 0;
        int result = 0;
        Map<Character, Integer> countMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
            while (countMap.get(c) >= k) {
                result += s.length() - i;
                char leftChar = s.charAt(left);
                countMap.put(leftChar, countMap.get(leftChar) - 1);
                left++;
            }
        }

        return result;
    }
}