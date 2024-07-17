class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int length = capacity.length;
        for (int i = 0; i < length; i++) {
            capacity[i] -= rocks[i];
        }

        Arrays.sort(capacity);
        int result = 0;
        for (int bag : capacity) {
            if (bag <= additionalRocks) {
                result++;
                additionalRocks -= bag;
            } else {
                break;
            }
        }

        return result;
    }
}