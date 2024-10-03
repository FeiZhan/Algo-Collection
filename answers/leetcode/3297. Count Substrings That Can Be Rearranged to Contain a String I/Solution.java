class Solution {
    public long validSubstringCount(String word1, String word2) {
        Map<Character, Integer> prefixMap = new HashMap<>();
        for (char c : word2.toCharArray()) {
            prefixMap.put(c, prefixMap.getOrDefault(c, 0) + 1);
        }
        boolean matched = false;
        int left = 0;
        long result = 0l;
        Map<Character, Integer> charMap = new HashMap<>();
        for (int i = 0; i < word1.length(); i++) {
            char c = word1.charAt(i);
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
            if (!matched && charMap.size() >= prefixMap.size() && charMap.get(c) >= prefixMap.getOrDefault(c, 0)) {
                matched = true;
                for (char prefixChar : prefixMap.keySet()) {
                    if (prefixMap.get(prefixChar) > charMap.getOrDefault(prefixChar, 0)) {
                        matched = false;
                        break;
                    }
                }
            }
            if (matched) {
                while (left < i) {
                    char leftChar = word1.charAt(left);
                    if (charMap.get(leftChar) <= prefixMap.getOrDefault(leftChar, 0)) {
                        break;
                    }
                    charMap.put(leftChar, charMap.get(leftChar) - 1);
                    left++;
                }
                result += left + 1;
            }
            System.out.println(left + " - " + i + " " + matched + " " + result);
        }

        return result;
    }
}