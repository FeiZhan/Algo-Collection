class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        Arrays.sort(score, (row0, row1) -> row1[k] - row0[k]);
        return score;
    }
}