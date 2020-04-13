class Solution {
    public double[] sampleStats(int[] count) {
        int countValue = 0;
        int maxCount = 0;
        double[] result = new double[5];
        result[0] = Integer.MAX_VALUE;
        result[1] = Integer.MIN_VALUE;
        for (int i = 0; i < count.length; i++) {
            int c = count[i];
            if (c > 0) {
                countValue += c;
                result[0] = Math.min(result[0], i);
                result[1] = Math.max(result[1], i);
                result[2] += c * i;
                if (c > maxCount) {
                    maxCount = c;
                    result[4] = i;
                }
            }
        }
        result[2] /= countValue;
        int half = 0;
        int left = 0;
        int right = 0;
        for (; right < count.length; right++) {
            half += count[right];
            if (half * 2 > countValue) {
                break;
            }
            if (count[right] > 0) {
                left = right;
            }
        }
        /*System.out.println(countValue + " " + half);
        System.out.println(left + " " + count[left]);
        System.out.println(right + " " + count[right]);*/
        result[3] = (half - count[right]) * 2 == countValue ? (left + right) / 2.0 : right;
        return result;
    }
}