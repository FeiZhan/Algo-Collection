class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> results = new LinkedList<>();
        for (int number : nums) {
            backtrack(number, new LinkedList<>(), results, nums);
        }

        return results;
    }

    private void backtrack(int current, List<Integer> numbers, List<List<Integer>> results, int[] nums) {
        numbers.add(current);
        if (numbers.size() == nums.length) {
            results.add(new LinkedList<>(numbers));
        } else {
            for (int number : nums) {
                if (!numbers.contains(number)) {
                    backtrack(number, numbers, results, nums);
                }
            }
        }

        numbers.remove(numbers.size() - 1);
    }
}
//Runtime: 7 ms, faster than 7.28% of Java online submissions for Permutations.
//Memory Usage: 42.1 MB, less than 6.23% of Java online submissions for Permutations.
