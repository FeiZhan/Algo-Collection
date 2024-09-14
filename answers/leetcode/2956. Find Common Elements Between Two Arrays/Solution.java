class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {
        Set<Integer> numberSet1 = new HashSet<>();
        for (int number : nums1) {
            numberSet1.add(number);
        }
        int[] result = new int[2];
        Set<Integer> numberSet2 = new HashSet<>();
        for (int number : nums2) {
            numberSet2.add(number);
            if (numberSet1.contains(number)) {
                result[1]++;
            }
        }
        for (int number : nums1) {
            if (numberSet2.contains(number)) {
                result[0]++;
            }
        }

        return result;
    }
}