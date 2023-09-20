class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int distance = 0;
        int unknown = 0;

        for (char c : moves.toCharArray()) {
            switch (c) {
                case 'L':
                    distance--;
                    break;
                case 'R':
                    distance++;
                    break;
                default:
                    unknown++;
                    break;
            }
        }

        return Math.abs(distance) + unknown;
    }
}