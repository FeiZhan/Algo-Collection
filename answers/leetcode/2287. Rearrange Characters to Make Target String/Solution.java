class Solution {
    public int rearrangeCharacters(String s, String target) {
        Map<Character, Integer> targetMap = new HashMap<>();
        for (char c : target.toCharArray()) {
            targetMap.put(c, targetMap.getOrDefault(c, 0) + 1);
        }

        Map<Character, Integer> charMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }

        int result = Integer.MAX_VALUE;
        for (char c : targetMap.keySet()) {
            int targetCount = targetMap.get(c);
            int count = charMap.getOrDefault(c, 0);
            result = Math.min(result, count / targetCount);
        }

        return result;
    }
}
//Runtime: 3 ms, faster than 29.57% of Java online submissions for Rearrange Characters to Make Target String.
//Memory Usage: 42.5 MB, less than 20.11% of Java online submissions for Rearrange Characters to Make Target String.
