class Solution {
    public String lastNonEmptyString(String s) {
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }

        int max = 0;
        Set<Character> maxSet = new HashSet<>();
        for (char c : countMap.keySet()) {
            int count = countMap.get(c);
            if (count > max) {
                max = count;
                maxSet.clear();
            }
            if (count == max) {
                maxSet.add(c);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (maxSet.contains(c)) {
                sb.insert(0, c);
                maxSet.remove(c);
            }
        }

        return sb.toString();
    }
}