class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        Map<Integer, Integer> counts = new HashMap<>();

        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums1) {
            numberSet.add(number);
        }
        for (int number : numberSet) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }

        numberSet = new HashSet<>();
        for (int number : nums2) {
            numberSet.add(number);
        }
        for (int number : numberSet) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }

        numberSet = new HashSet<>();
        for (int number : nums3) {
            numberSet.add(number);
        }
        for (int number : numberSet) {
            counts.put(number, counts.getOrDefault(number, 0) + 1);
        }

        List<Integer> result = new LinkedList<>();
        for (int number : counts.keySet()) {
            int count = counts.get(number);
            if (count >= 2) {
                result.add(number);
            }
        }

        return result;
    }
}