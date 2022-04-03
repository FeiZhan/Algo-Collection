class Solution {
    public int countCollisions(String directions) {
        int result = directions.length();
        for (int i = 0; i < directions.length(); i++) {
            char c = directions.charAt(i);
            if (c == 'S') {
                result--;
            }
        }
        for (int i = 0; i < directions.length(); i++) {
            char c = directions.charAt(i);
            if (c == 'L') {
                result--;
            } else {
                break;
            }
        }
        for (int i = directions.length() - 1; i >= 0; i--) {
            char c = directions.charAt(i);
            if (c == 'R') {
                result--;
            } else {
                break;
            }
        }

        return result;
    }
}
//Runtime: 21 ms, faster than 78.85% of Java online submissions for Count Collisions on a Road.
//Memory Usage: 55.1 MB, less than 35.64% of Java online submissions for Count Collisions on a Road.
