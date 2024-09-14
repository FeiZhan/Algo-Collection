class Solution {
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        Map<Character, Character> charMap = new HashMap<>();
        Map<Character, Set<Character>> unionMap = new HashMap<>();
        for (int i = 0; i < s1.length(); i++) {
            char c1 = charMap.getOrDefault(s1.charAt(i), s1.charAt(i));
            char c2 = charMap.getOrDefault(s2.charAt(i), s2.charAt(i));
            char smaller = c1 <= c2 ? c1 : c2;
            Set<Character> c1Set = unionMap.getOrDefault(c1, new HashSet<>());
            c1Set.add(c1);
            unionMap.remove(c1);
            Set<Character> c2Set = unionMap.getOrDefault(c2, new HashSet<>());
            c1Set.add(c2);
            unionMap.remove(c2);
            c1Set.addAll(c2Set);
            unionMap.put(smaller, c1Set);
            for (char c : c1Set) {
                charMap.put(c, smaller);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (char c : baseStr.toCharArray()) {
            sb.append(charMap.getOrDefault(c, c));
        }

        return sb.toString();
    }
}