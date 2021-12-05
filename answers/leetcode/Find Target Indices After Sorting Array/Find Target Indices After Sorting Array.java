class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int smaller = 0;
        int equal = 0;
        for (int number : nums) {
            smaller += number < target ? 1 : 0;
            equal += number == target ? 1 : 0;
        }

        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < equal; i++) {
            result.add(smaller + i);
        }

        return result;
    }
}
//Runtime: 1 ms, faster than 88.37% of Java online submissions for Find Target Indices After Sorting Array.
//Memory Usage: 39.2 MB, less than 59.48% of Java online submissions for Find Target Indices After Sorting Array.
