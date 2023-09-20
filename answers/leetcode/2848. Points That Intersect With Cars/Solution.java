class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        Set<Integer> points = new HashSet<>();
        for (List<Integer> car : nums) {
            for (int i = car.get(0); i <= car.get(1); i++) {
                points.add(i);
            }
        }

        return points.size();
    }
}