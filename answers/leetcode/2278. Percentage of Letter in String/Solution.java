class Solution {
    public int percentageLetter(String s, char letter) {
        int count = 0;
        for (char c : s.toCharArray()) {
            count += c == letter ? 1 : 0;
        }

        return count * 100 / s.length();
    }
}
//Runtime: 0 ms, faster than 100.00% of Java online submissions for Percentage of Letter in String.
//Memory Usage: 40.4 MB, less than 75.00% of Java online submissions for Percentage of Letter in String.
