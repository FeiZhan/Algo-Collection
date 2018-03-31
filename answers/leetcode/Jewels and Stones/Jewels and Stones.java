class Solution {
    public int numJewelsInStones(String J, String S) {
        int jewels = 0;
        for (char j : J.toCharArray()) {
            for (char s : S.toCharArray()) {
                jewels += s == j ? 1 : 0;
            }
        }
        return jewels;
    }
}