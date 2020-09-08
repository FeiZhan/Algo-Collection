class Solution {
    public int numSplits(String s) {
        Map<Character, Integer> rightMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            rightMap.put(c, rightMap.getOrDefault(c, 0) + 1);
        }
        int count = 0;
        Map<Character, Integer> leftMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            leftMap.put(c, leftMap.getOrDefault(c, 0) + 1);
            rightMap.put(c, rightMap.get(c) - 1);
            if (rightMap.get(c) <= 0) {
                rightMap.remove(c);
            }
            if (leftMap.size() == rightMap.size()) {
                count++;
            }
        }
        return count;
    }
}