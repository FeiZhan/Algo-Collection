class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> results = new TreeSet<>();
        for (int i = 1; i <= bound; i *= x) {
            for (int j = 1; i + j <= bound; j *= y) {
                results.add(i + j);
                if (y == 1) {
                    break;
                }
            }
            if (x == 1) {
                break;
            }
        }
        return  new LinkedList<>(results);
    }
}