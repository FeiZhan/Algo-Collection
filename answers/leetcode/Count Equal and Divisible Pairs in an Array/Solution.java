class Solution {
    public int countPairs(int[] nums, int k) {
        int result = 0;
        Map<Integer, List<Integer>> numbers = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            List<Integer> list = numbers.getOrDefault(nums[i], new ArrayList<>());
            list.add(i);
            numbers.put(nums[i], list);
        }

        for (List<Integer> list : numbers.values()) {
            for (int i = 0; i < list.size(); i++) {
                for (int j = i + 1; j < list.size(); j++) {
                    if (list.get(i) * list.get(j) % k == 0) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
}