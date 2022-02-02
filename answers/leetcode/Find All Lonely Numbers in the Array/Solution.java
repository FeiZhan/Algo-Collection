class Solution {
    public List<Integer> findLonely(int[] nums) {
        Map<Integer, Integer> numbers = new HashMap<>();
        for (int number : nums) {
            numbers.put(number, numbers.getOrDefault(number, 0) + 1);
        }

        List<Integer> result = new LinkedList<>();
        for (int number : numbers.keySet()) {
            if (numbers.get(number) == 1 && !numbers.containsKey(number - 1) && !numbers.containsKey(number + 1)) {
                result.add(number);
            }
        }

        return result;
    }
}
//Runtime: 274 ms, faster than 7.97% of Java online submissions for Find All Lonely Numbers in the Array.
//Memory Usage: 177.4 MB, less than 26.02% of Java online submissions for Find All Lonely Numbers in the Array.
