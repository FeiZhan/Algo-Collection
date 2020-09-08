class Solution {
    public List<Integer> mostVisited(int n, int[] rounds) {
        int last = rounds[rounds.length - 1];
        List<Integer> result = new LinkedList<>();
        if (rounds[0] <= last) {
            for (int i = rounds[0]; i <= last; i++) {
                result.add(i);
            }
        } else {
            for (int i = 1; i <= last; i++) {
                result.add(i);
            }
            for (int i = rounds[0]; i <= n; i++) {
                result.add(i);
            }
        }
        return result;
    }
}