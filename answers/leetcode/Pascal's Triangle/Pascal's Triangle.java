class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<List<Integer>>();
        if (numRows > 0) {
            List<Integer> row = new ArrayList<Integer>();
            row.add(1);
            triangle.add(row);
        }
        for (int i = 1; i < numRows; i++) {
            List<Integer> row = new ArrayList<Integer>(triangle.get(i - 1));
            row.add(0, 0);
            row.add(0);
            List<Integer> next = new ArrayList<Integer>();
            for (int j = 1; j < row.size(); j++) {
                next.add(row.get(j - 1) + row.get(j));
            }
            triangle.add(next);
        }
        return triangle;
    }
}