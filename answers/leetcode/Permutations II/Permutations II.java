class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Map<Integer, Integer> numberMap = new HashMap<>();
        for (int number : nums) {
            numberMap.put(number, numberMap.getOrDefault(number, 0) + 1);
        }

        List<List<Integer>> results = new LinkedList<>();
        backtrack(new LinkedList<>(), results, numberMap, nums.length);

        return results;
    }

    private void backtrack(List<Integer> permutation, List<List<Integer>> results, Map<Integer, Integer> numberMap, int size) {
        if (permutation.size() == size) {
            results.add(new LinkedList<>(permutation));
            return;
        }

        for (int number : numberMap.keySet()) {
            int count = numberMap.get(number);
            if (count > 0) {
                permutation.add(number);
                numberMap.put(number, count - 1);
                backtrack(permutation, results, numberMap, size);
                permutation.remove(permutation.size() - 1);
                numberMap.put(number, count);
            }
        }
    }
}
//Runtime: 3 ms, faster than 54.65% of Java online submissions for Permutations II.
//Memory Usage: 39.8 MB, less than 62.91% of Java online submissions for Permutations II.
