class Solution {
    public List<String> simplifiedFractions(int n) {
        List<String> result = new LinkedList<>();
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (this.gcd(i, j) == 1) {
                    String fraction = Integer.toString(j) + '/' + Integer.toString(i);
                    result.add(fraction);
                }
            }
        }
        return result;
    }

    private int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
}