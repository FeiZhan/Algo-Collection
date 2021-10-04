class Solution {
    public int minimumMoves(String s) {
        int moves = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'X') {
                moves++;
                i += 2;
            }
        }

        return moves;
    }
}