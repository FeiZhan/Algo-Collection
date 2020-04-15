class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int[][] result = new int[mat.length][mat[0].length];
        for (int i = 0; i < mat.length; i++) {
            PriorityQueue<Integer> queue = new PriorityQueue<>();
            for (int j = 0; i + j < mat.length && j < mat[0].length; j++) {
                queue.add(mat[i + j][j]);
            }
            for (int j = 0; i + j < mat.length && j < mat[0].length; j++) {
                result[i + j][j] = queue.poll();
            }
        }
        for (int i = 1; i < mat[0].length; i++) {
            PriorityQueue<Integer> queue = new PriorityQueue<>();
            for (int j = 0; j < mat.length && i + j < mat[0].length; j++) {
                queue.add(mat[j][i + j]);
            }
            for (int j = 0; j < mat.length && i + j < mat[0].length; j++) {
                result[j][i + j] = queue.poll();
            }
        }
        return result;
    }
}