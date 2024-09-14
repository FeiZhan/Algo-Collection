class Solution {
    public int minimumLength(String s) {
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }

        int result = 0;
        for (int count : countMap.values()) {
            result += count % 2 == 0 ? 2 : 1;
        }

        return result;
    }
}