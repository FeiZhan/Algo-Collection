class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int left = 0;
        int right = 0;
        for (int weight : weights) {
            left = Math.max(left, weight);
            right += weight;
        }
        while (left < right) {
            int count = 0;
            int middle = (left + right) / 2;
            int sum = 0;
            for (int weight : weights) {
                sum += weight;
                if (sum > middle) {
                    sum = weight;
                    count++;
                    if (count > D) {
                        break;
                    }
                }
            }
            if (sum > 0) {
                count++;
            }
            if (count > D) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        return left;
    }
}