class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        Map<Integer, Integer> numberMap = new HashMap<>();
        for (int number : nums) {
            numberMap.put(number, numberMap.getOrDefault(number, 0) + 1);
        }

        List<List<Integer>> result = new LinkedList<>();
        while (!numberMap.isEmpty()) {
            List<Integer> list = new LinkedList<>(numberMap.keySet());
            for (int number : list) {
                numberMap.put(number, numberMap.get(number) - 1);
                if (numberMap.get(number) == 0) {
                    numberMap.remove(number);
                }
            }
            result.add(list);
        }

        return result;
    }
}