class Solution {
    public int characterReplacement(String s, int k) {
        if (null == s || 0 == s.length()) {
            return 0;
        }
        Map<Character, Integer> charMap = new HashMap<>();
        char mainChar = s.charAt(0);
        int maxLength = 0;
        for (int i = 0, j = 0; j < s.length(); j++) {
            char c = s.charAt(j);
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
            if (charMap.get(c) > charMap.get(mainChar)) {
                mainChar = c;
            }
            int replacement = j - i + 1 - charMap.get(mainChar);
            while (replacement > k) {
                char c1 = s.charAt(i);
                charMap.put(c1, charMap.get(c1) - 1);
                if (c1 == mainChar) {
                    for (char c2 : charMap.keySet()) {
                        if (charMap.get(c2) > charMap.get(mainChar)) {
                            mainChar = c2;
                            break;
                        }
                    }
                }
                i++;
                replacement = j - i + 1 - charMap.get(mainChar);
            }
            maxLength = Math.max(maxLength, j - i + 1);
            //System.out.println(i + "-" + j + ": " + mainChar + " " + replacement);
        }
        return maxLength;
    }
}