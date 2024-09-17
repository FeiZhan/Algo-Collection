class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int result = 0;
        for (String command : commands) {
            switch (command) {
                case "UP":
                    result -= n;
                    break;
                case "DOWN":
                    result += n;
                    break;
                case "LEFT":
                    result--;
                    break;
                case "RIGHT":
                    result++;
                    break;
            }
        }

        return result;
    }
}