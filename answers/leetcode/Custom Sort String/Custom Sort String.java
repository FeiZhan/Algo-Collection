class Solution {
    public String customSortString(String S, String T) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (char c : T.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }
        Set<Character> charSet = new HashSet<>();
        StringBuilder sb = new StringBuilder();
        for (char c : S.toCharArray()) {
            charSet.add(c);
            for (int i = 0; i < charMap.getOrDefault(c, 0); i++) {
                sb.append(c);
            }
        }
        for (char c : charMap.keySet()) {
            if (!charSet.contains(c)) {
                for (int i = 0; i < charMap.get(c); i++) {
                    sb.append(c);
                }
            }
        }
        return sb.toString();
    }
}