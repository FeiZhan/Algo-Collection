class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int[] result = new int[2];
        Set<Integer> numberSet = new HashSet<>();
        for (int number : nums) {
            if (numberSet.contains(number)) {
                result[1] = result[0];
                result[0] = number;
            } else {
                numberSet.add(number);
            }
        }

        return result;
    }
}