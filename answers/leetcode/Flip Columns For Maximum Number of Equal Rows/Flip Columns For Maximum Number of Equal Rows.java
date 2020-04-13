class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> counts = new HashMap<>();
        for (int[] row : matrix) {
            int sum = 0;
            for (int cell : row) {
                sum += cell;
            }
            if (sum * 2 > row.length || (sum * 2 == row.length && row[0] == 1)) {
                for (int i = 0; i < row.length; i++) {
                    row[i] = row[i] == 1 ? 0 : 1;
                }
            }
            String rowStr = Arrays.toString(row);
            counts.put(rowStr, counts.getOrDefault(rowStr, 0) + 1);
        }
        int maxCount = 0;
        for (int count : counts.values()) {
            maxCount = Math.max(maxCount, count);
        }
        return maxCount;
    }
}