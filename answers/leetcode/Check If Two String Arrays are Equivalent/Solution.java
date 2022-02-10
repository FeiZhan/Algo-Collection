class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        int arrayIndex1 = 0;
        int arrayIndex2 = 0;
        int stringIndex1 = 0;
        int stringIndex2 = 0;

        while (arrayIndex1 < word1.length && arrayIndex2 < word2.length) {
            String w1 = word1[arrayIndex1];
            String w2 = word2[arrayIndex2];
            char c1 = w1.charAt(stringIndex1);
            char c2 = w2.charAt(stringIndex2);

            if (c1 != c2) {
                return false;
            }

            stringIndex1++;
            if (stringIndex1 >= w1.length()) {
                arrayIndex1++;
                stringIndex1 = 0;
            }

            stringIndex2++;
            if (stringIndex2 >= w2.length()) {
                arrayIndex2++;
                stringIndex2 = 0;
            }
        }

        return arrayIndex1 == word1.length && arrayIndex2 == word2.length;
    }
}
//Runtime: 4 ms, faster than 8.46% of Java online submissions for Check If Two String Arrays are Equivalent.
//Memory Usage: 41.8 MB, less than 14.82% of Java online submissions for Check If Two String Arrays are Equivalent.
