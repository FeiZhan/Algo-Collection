class Solution {
    public String largestMerge(String word1, String word2) {
        StringBuilder sb1 = new StringBuilder(word1);
        StringBuilder sb2 = new StringBuilder(word2);
        StringBuilder result = new StringBuilder();

        while (sb1.length() > 0 && sb2.length() > 0) {
            char c1 = sb1.length() > 0 ? sb1.charAt(0) : ' ';
            char c2 = sb2.length() > 0 ? sb2.charAt(0) : ' ';
            if (c1 > c2) {
                sb1.deleteCharAt(0);
                result.append(c1);
            } else if (c1 < c2) {
                sb2.deleteCharAt(0);
                result.append(c2);
            } else {
                int compare = sb1.compareTo(sb2);
                if (compare >= 0) {
                    sb1.deleteCharAt(0);
                    result.append(c1);
                } else {
                    sb2.deleteCharAt(0);
                    result.append(c2);
                }
            }
        }
        result.append(sb1).append(sb2);

        return result.toString();
    }
}