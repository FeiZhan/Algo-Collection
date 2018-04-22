class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int num : nums) {
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }
        List<List<Integer>> result = new ArrayList<>();
        this.backtrack(0, 0, numMap, new ArrayList<>(), result);
        return result;
    }

    private void backtrack(int index, int count, Map<Integer, Integer> numMap, List<Integer> subset, List<List<Integer>> result) {
        result.add(new ArrayList<>(subset));
        List<Integer> keySet = new ArrayList<Integer>(numMap.keySet());
        if (count < numMap.get(keySet.get(index))) {
            subset.add(keySet.get(index));
            this.backtrack(index, count + 1, numMap, subset, result);
            subset.remove(subset.size() - 1);
        }
        for (int i = index + 1; i < keySet.size(); i++) {
            subset.add(keySet.get(i));
            this.backtrack(i, 1, numMap, subset, result);
            subset.remove(subset.size() - 1);
        }
    }
}