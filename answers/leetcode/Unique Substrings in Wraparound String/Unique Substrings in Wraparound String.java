class Solution {
    public int findSubstringInWraproundString(String p) {
        int[] letters = new int[26];
        int count = 1;
        for (int i = 0; i < p.length(); i++) {
            if (i > 0 && (p.charAt(i) == p.charAt(i - 1) + 1 || ('a' == p.charAt(i) && 'z' == p.charAt(i - 1)))) {
                count++;
            } else {
                count = 1;
            }
            int index = p.charAt(i) - 'a';
            letters[index] = Math.max(letters[index], count);
        }
        int sum = 0;
        for (int letter : letters) {
            sum += letter;
        }
        return sum;
    }
}