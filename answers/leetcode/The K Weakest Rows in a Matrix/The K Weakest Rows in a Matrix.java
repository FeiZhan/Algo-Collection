class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int[] counts = new int[mat.length];
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                counts[i] += mat[i][j];
            }
        }
        PriorityQueue<Integer> queue = new PriorityQueue<>((c0, c1) -> {
            if (counts[c0] != counts[c1]) {
                return counts[c0] - counts[c1];
            } else {
                return c0 - c1;
            }
        });
        for (int i = 0; i < counts.length; i++) {
            queue.add(i);
        }
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            if (!queue.isEmpty()) {
                result[i] = queue.poll();
            }
        }
        return result;
    }
}