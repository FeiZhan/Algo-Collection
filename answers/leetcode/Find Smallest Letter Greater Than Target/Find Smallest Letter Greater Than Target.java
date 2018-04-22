class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        char smallest = 'z';
        char greater = '.';
        for (char c : letters) {
            smallest = smallest > c ? c : smallest;
            if (c > target && (greater == '.' || greater > c)) {
                greater = c;
            }
        }
        return greater == '.' ? smallest : greater;
    }
}