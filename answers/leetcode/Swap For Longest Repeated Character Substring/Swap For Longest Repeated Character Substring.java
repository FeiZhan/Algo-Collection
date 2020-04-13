class Solution {
    public int maxRepOpt1(String text) {
        char current = '.';
        int count = 0;
        List<Character> chars = new ArrayList<>();
        List<Integer> counts = new ArrayList<>();
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : text.toCharArray()) {
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
            if (current != c) {
                if (count > 0) {
                    chars.add(current);
                    counts.add(count);
                }
                current = c;
                count = 0;
            }
            count++;
        }
        if (count > 0) {
            chars.add(text.charAt(text.length() - 1));
            counts.add(count);
        }
        int maxLength = 0;
        for (int i = 0; i < chars.size(); i++) {
            char c = chars.get(i);
            int allCount = countMap.get(c);
            int currentCount = counts.get(i);
            int length = currentCount + (allCount > currentCount ? 1 : 0);
            if (i >= 2 && chars.get(i - 2) == c && counts.get(i - 1) == 1
                && allCount >= currentCount + counts.get(i - 2)) {
                length = Math.min(allCount, currentCount + counts.get(i - 2) + 1);
            }
            maxLength = Math.max(maxLength, length);
        }
        return maxLength;
    }
}