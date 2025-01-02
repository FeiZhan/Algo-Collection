class Solution {
    public List<Integer> getGoodIndices(int[][] variables, int target) {
        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < variables.length; i++) {
            int a = variables[i][0];
            int b = variables[i][1];
            int result0 = 1;
            for (int j = 0; j < b; j++) {
                result0 = (result0 * a) % 10;
            }
            int c = variables[i][2];
            int m = variables[i][3];
            int result1 = 1;
            for (int j = 0; j < c; j++) {
                result1 = (result1 * result0) % m;
            }
            if (result1 == target) {
                result.add(i);
            }
        }

        return result;
    }
}