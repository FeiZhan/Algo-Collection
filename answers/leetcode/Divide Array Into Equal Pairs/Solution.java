class Solution {
    public boolean divideArray(int[] nums) {
        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums) {
            if (numberSet.contains(number)) {
                numberSet.remove(number);
            } else {
                numberSet.add(number);
            }
        }

        return numberSet.isEmpty();
    }
}
//Runtime: 11 ms, faster than 27.85% of Java online submissions for Divide Array Into Equal Pairs.
//Memory Usage: 48.5 MB, less than 24.24% of Java online submissions for Divide Array Into Equal Pairs.
