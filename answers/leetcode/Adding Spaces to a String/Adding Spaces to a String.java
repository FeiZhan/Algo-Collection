class Solution {
    public String addSpaces(String s, int[] spaces) {
        char[] result = new char[s.length() + spaces.length];
        int spaceIndex = 0;

        for (int i = 0; i <= s.length(); i++) {
            if (spaceIndex < spaces.length && i == spaces[spaceIndex]) {
                result[i + spaceIndex] = ' ';
                spaceIndex++;
            }
            if (i < s.length()) {
                result[i + spaceIndex] = s.charAt(i);
            }
        }

        return String.valueOf(result);
    }
}
//Runtime: 28 ms, faster than 55.46% of Java online submissions for Adding Spaces to a String.
//Memory Usage: 113.7 MB, less than 42.03% of Java online submissions for Adding Spaces to a String.
