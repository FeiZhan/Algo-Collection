class Solution {
    public int binaryGap(int N) {
        int gap = 0;
        int distance = -1;
        while (N != 0) {
            if (distance >= 0) {
                distance++;
            }
            if (N % 2 == 1) {
                if (distance >= 0) {
                    gap = Math.max(gap, distance);
                }
                distance = 0;
            }
            N /= 2;
        }
        return gap;
    }
}