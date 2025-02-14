class Solution {
    public int maxDifference(String s) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }
        int evenMin = Integer.MAX_VALUE;
        int oddMax = 0;
        for (int count : charMap.values()) {
            if (count % 2 == 0) {
                evenMin = Math.min(evenMin, count);
            } else {
                oddMax = Math.max(oddMax, count);
            }
        }

        return oddMax - evenMin;
    }
}