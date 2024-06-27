class Solution {
    public int maximumSetSize(int[] nums1, int[] nums2) {
        Set<Integer> numbers1 = new HashSet<>();
        for (int number : nums1) {
            numbers1.add(number);
        }
        int setSize1 = numbers1.size();
        Set<Integer> numbers2 = new HashSet<>();
        for (int number : nums2) {
            numbers2.add(number);
        }
        int setSize2 = numbers2.size();
        Set<Integer> intersection = new HashSet<>(numbers1);
        intersection.retainAll(numbers2);
        int intersectionSize = intersection.size();
        int unionSize = setSize1 + setSize2 - intersectionSize;

        int overflow1 = setSize1 - nums1.length / 2;
        int overflow2 = setSize2 - nums2.length / 2;
        if (overflow1 <= 0 && overflow2 <= 0) {
            return unionSize;
        }

        int overflow = Math.max(overflow1, 0) + Math.max(overflow2, 0) - intersectionSize;
        return unionSize - Math.max(overflow, 0);
    }
}