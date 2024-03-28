class Solution {
    public int minimumOperationsToWriteY(int[][] grid) {
        Map<Integer, Integer> counts = new HashMap<>();
        for (int[] row : grid) {
            for (int number : row) {
                counts.put(number, counts.getOrDefault(number, 0) + 1);
            }
        }

        int length = grid.length;
        Map<Integer, Integer> yCounts = new HashMap<>();
        int temp = grid[length / 2][length / 2];
        yCounts.put(temp, 1);
        counts.put(temp, counts.get(temp) - 1);

        for (int i = 0; i + i + 1 < length; i++) {
            int number = grid[i][i];
            yCounts.put(number, yCounts.getOrDefault(number, 0) + 1);
            counts.put(number, counts.get(number) - 1);

            number = grid[i][length - 1 - i];
            yCounts.put(number, yCounts.getOrDefault(number, 0) + 1);
            counts.put(number, counts.get(number) - 1);

            number = grid[length - 1 - i][length / 2];
            yCounts.put(number, yCounts.getOrDefault(number, 0) + 1);
            counts.put(number, counts.get(number) - 1);
        }

        int[] frequency = new int[] {0, 0};
        int[] frequentNumbers = new int[] {0, 0};
        for (int number : counts.keySet()) {
            int count = counts.get(number);
            if (count > frequency[0]) {
                frequency[1] = frequency[0];
                frequentNumbers[1] = frequentNumbers[0];
                frequency[0] = count;
                frequentNumbers[0] = number;
            } else if (count > frequency[1]) {
                frequency[1] = count;
                frequentNumbers[1] = number;
            }
        }

        int[] yFrequency = new int[] {0, 0};
        int[] yFrequentNumbers = new int[] {0, 0};
        for (int number : yCounts.keySet()) {
            int count = yCounts.get(number);
            if (count > yFrequency[0]) {
                yFrequency[1] = yFrequency[0];
                yFrequentNumbers[1] = yFrequentNumbers[0];
                yFrequency[0] = count;
                yFrequentNumbers[0] = number;
            } else if (count > yFrequency[1]) {
                yFrequency[1] = count;
                yFrequentNumbers[1] = number;
            }
        }

        int result = 0;
        if (frequentNumbers[0] != yFrequentNumbers[0]) {
            result = length * length - frequency[0] - yFrequency[0];
        } else {
            result = length * length - Math.max(frequency[0] + yFrequency[1], frequency[1] + yFrequency[0]);
        }

        //System.out.println(counts.size() + " " + yCounts.size() + " " + frequency[0] + " " + frequency[1] + " " + yFrequency[0] + " " + yFrequency[1]);
        return result;
    }
}