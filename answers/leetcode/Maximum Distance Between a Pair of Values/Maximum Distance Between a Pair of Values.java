class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int result = 0;
        for (int i = 0, j = 0; i < nums1.length; i++) {
            for (; j < nums2.length; j++) {
                if (nums1[i] > nums2[j]) {
                    result = Math.max(result, j - i - 1);
                    break;
                }
            }
            if (j == nums2.length) {
                result = Math.max(result, j - i - 1);
            }
        }

        return result;
    }
}