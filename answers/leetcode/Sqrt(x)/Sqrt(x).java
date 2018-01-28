class Solution {
    public int mySqrt(int x) {
        // Avoid divided by 0
        if (0 == x) {
            return 0;
        }

        int left = 1;
        int right = x;
        while (left <= right) {
            int middle = (left + right) / 2;
            // Use division to accelerate
            if (middle <= x / middle) {
                if (middle <= x / middle && (middle + 1) > x / (middle + 1)) {
                    return middle;
                } else {
                    left = middle + 1;
                }
            } else {
                right = middle - 1;
            }
        }
        return -1;
    }
}