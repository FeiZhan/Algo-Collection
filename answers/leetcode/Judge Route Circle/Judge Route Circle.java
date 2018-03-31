class Solution {
    public boolean judgeCircle(String moves) {
        int x = 0;
        int y = 0;
        for (char c : moves.toCharArray()) {
            switch (c) {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y--;
                    break;
                case 'D':
                    y++;
                    break;
            }
        }
        return x == 0 && y == 0;
    }
}