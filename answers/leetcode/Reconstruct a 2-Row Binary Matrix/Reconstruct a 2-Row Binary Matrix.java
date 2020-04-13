class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        List<List<Integer>> matrix = new ArrayList<>();
        matrix.add(new ArrayList<>());
        matrix.add(new ArrayList<>());
        for (int i = 0; i < colsum.length; i++) {
            int number = colsum[i] == 2 ? 1 : 0;
            matrix.get(0).add(number);
            matrix.get(1).add(number);
            upper -= number;
            lower -= number;
        }
        for (int i = 0; i < colsum.length; i++) {
            if (colsum[i] == 1) {
                if (upper > 0) {
                    matrix.get(0).set(i, 1);
                    upper--;
                } else if (lower > 0) {
                    matrix.get(1).set(i, 1);
                    lower--;
                } else {
                    return new ArrayList<>();
                }
            }
        }
        return upper == 0 && lower == 0 ? matrix : new ArrayList<>();
    }
}