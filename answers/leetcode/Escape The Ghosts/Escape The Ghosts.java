class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int distance = Math.abs(target[0]) + Math.abs(target[1]);
        for (int[] ghost : ghosts) {
            int d = Math.abs(ghost[0] - target[0]) + Math.abs(ghost[1] - target[1]);
            if (d < distance) {
                return false;
            }
        }
        return true;
    }
}