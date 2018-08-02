class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> positions = new LinkedList<>();
        int left = 0;
        int right = 0;
        while (right <= S.length()) {
            if (right == S.length() || S.charAt(left) != S.charAt(right)) {
                if (right - left >= 3) {
                    List<Integer> position = new LinkedList<>();
                    position.add(left);
                    position.add(right - 1);
                    positions.add(position);
                }
                left = right;
            }
            right++;
        }
        return positions;
    }
}