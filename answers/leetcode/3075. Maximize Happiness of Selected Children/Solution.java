class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long result = 0l;
        for (int i = 0; i < k; i++) {
            int max = happiness[happiness.length - i - 1] - i;
            result += Math.max(max, 0);
        }

        return result;
    }
}