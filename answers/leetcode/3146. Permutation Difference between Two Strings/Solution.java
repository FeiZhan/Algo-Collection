class Solution {
    public int findPermutationDifference(String s, String t) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            charMap.put(s.charAt(i), i);
        }

        int result = 0;
        for (int i = 0; i < t.length(); i++) {
            result += Math.abs(i - charMap.get(t.charAt(i)));
        }

        return result;
    }
}