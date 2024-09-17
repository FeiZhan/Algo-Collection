class Solution {
    public int maximumScore(int a, int b, int c) {
        int result = 0;
        int[] piles = new int[]{a, b, c};
        while (true) {
            Arrays.sort(piles);
            if (piles[1] == 0) {
                break;
            }
            piles[1]--;
            piles[2]--;
            result += 1;
        }

        return result;
    }
}