class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        List<Integer> total = new ArrayList<>();
        for (int i = 0; i < triangle.size(); i++) {
            List<Integer> newTotal = new ArrayList<>();
            for (int j = 0; j < triangle.get(i).size(); j++) {
                int sum = Integer.MAX_VALUE;
                if (j < total.size()) {
                    sum = Math.min(sum, triangle.get(i).get(j) + total.get(j));
                }
                if (j > 0) {
                    sum = Math.min(sum, triangle.get(i).get(j) + total.get(j - 1));
                }
                if (sum == Integer.MAX_VALUE) {
                    sum = triangle.get(i).get(j);
                }
                newTotal.add(sum);
            }
            total = newTotal;
        }
        int minTotal = Integer.MAX_VALUE;
        for (int sum : total) {
            minTotal = Math.min(minTotal, sum);
        }
        return minTotal;
    }
}