class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int[] result = new int[2];
        Set<Integer> numberSet = new HashSet<>();
        for (int[] row : grid) {
            for (int number : row) {
                if (numberSet.contains(number)) {
                    result[0] = number;
                } else {
                    numberSet.add(number);
                }
            }
        }
        int maxValue = grid.length * grid.length;
        for (int i = 1; i <= maxValue; i++) {
            if (!numberSet.contains(i)) {
                result[1] = i;
                break;
            }
        }

        return result;
    }
}