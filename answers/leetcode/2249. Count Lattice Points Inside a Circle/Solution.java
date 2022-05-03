class Solution {
    public int countLatticePoints(int[][] circles) {
        Set<Integer> pointSet = new HashSet<>();

        for (int[] circle : circles) {
            for (int i = -circle[2]; i <= circle[2]; i++) {
                for (int j = -circle[2]; j <= circle[2]; j++) {
                    if (i * i + j * j <= circle[2] * circle[2]) {
                        pointSet.add((circle[0] + i) * 1000 + circle[1] + j);
                    }
                }
            }
        }

        return pointSet.size();
    }
}
//Runtime: 177 ms, faster than 74.66% of Java online submissions for Count Lattice Points Inside a Circle.
//Memory Usage: 48.3 MB, less than 67.05% of Java online submissions for Count Lattice Points Inside a Circle.
