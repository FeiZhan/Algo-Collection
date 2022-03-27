class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> numberSet1 = new HashSet<>();
        for (int number : nums1) {
            numberSet1.add(number);
        }
        Set<Integer> numberSet2 = new HashSet<>();
        for (int number : nums2) {
            numberSet2.add(number);
        }

        List<List<Integer>> result = new LinkedList<>();
        List<Integer> absent1 = new LinkedList<>();
        for (int number : numberSet1) {
            if (!numberSet2.contains(number)) {
                absent1.add(number);
            }
        }
        result.add(absent1);

        List<Integer> absent2 = new LinkedList<>();
        for (int number : numberSet2) {
            if (!numberSet1.contains(number)) {
                absent2.add(number);
            }
        }
        result.add(absent2);

        return result;
    }
}
//Runtime: 16 ms, faster than 33.33% of Java online submissions for Find the Difference of Two Arrays.
//Memory Usage: 55.5 MB, less than 66.67% of Java online submissions for Find the Difference of Two Arrays.
