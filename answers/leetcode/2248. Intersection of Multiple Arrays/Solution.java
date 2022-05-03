class Solution {
    public List<Integer> intersection(int[][] nums) {
        Set<Integer> numberSet = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            Set<Integer> set = new HashSet<>();
            for (int number : nums[i]) {
                set.add(number);
            }

            if (i == 0) {
                numberSet = set;
            } else {
                numberSet.retainAll(set);
            }
        }

        List<Integer> result = new ArrayList<>(numberSet);
        Collections.sort(result);

        return result;
    }
}
//Runtime: 5 ms, faster than 68.69% of Java online submissions for Intersection of Multiple Arrays.
//Memory Usage: 42.7 MB, less than 93.03% of Java online submissions for Intersection of Multiple Arrays.
