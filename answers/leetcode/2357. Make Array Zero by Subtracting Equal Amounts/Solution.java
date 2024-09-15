class Solution {
    public int minimumOperations(int[] nums) {
        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums) {
            if (number != 0) {
                numberSet.add(number);
            }
        }

        return numberSet.size();
    }
}