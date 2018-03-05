class Solution {
    private List<List<Integer>> triangle;

    public List<Integer> getRow(int rowIndex) {
        this.generate(rowIndex);
        return this.triangle.get(rowIndex);
    }

    private void generate(int numRows) {
        if (null == this.triangle) {
            this.triangle = new ArrayList<List<Integer>>();
            List<Integer> row = new ArrayList<Integer>();
            row.add(1);
            triangle.add(row);
        }
        if (this.triangle.size() > numRows) {
            return;
        }

        for (int i = this.triangle.size(); i <= numRows; i++) {
            List<Integer> row = new ArrayList<Integer>(triangle.get(i - 1));
            row.add(0, 0);
            row.add(0);
            List<Integer> next = new ArrayList<Integer>();
            for (int j = 1; j < row.size(); j++) {
                next.add(row.get(j - 1) + row.get(j));
            }
            triangle.add(next);
        }
    }
}