class Solution {
    public long shiftDistance(String s, String t, int[] nextCost, int[] previousCost) {
        long nextTotal = 0l;
        long[] nextSum = new long[nextCost.length + 1];
        for (int i = 0; i < nextCost.length; i++) {
            nextTotal += nextCost[i];
            nextSum[i + 1] = nextTotal;
        }
        long previousTotal = 0l;
        long[] previousSum = new long[previousCost.length + 1];
        for (int i = 0; i < previousCost.length; i++) {
            previousTotal += previousCost[i];
            previousSum[i + 1] = previousTotal;
        }
        long result = 0l;
        for (int i = 0; i < s.length(); i++) {
            int sIndex = (int)(s.charAt(i) - 'a');
            int tIndex = (int)(t.charAt(i) - 'a');
            if (sIndex < tIndex) {
                result += Math.min(nextSum[tIndex] - nextSum[sIndex], previousTotal - previousSum[tIndex + 1] + previousSum[sIndex + 1]);
            } else {
                result += Math.min(nextTotal - nextSum[sIndex] + nextSum[tIndex], previousSum[sIndex + 1] - previousSum[tIndex + 1]);
            }
        }

        return result;
    }
}