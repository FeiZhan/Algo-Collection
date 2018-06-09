class Solution {
    public int findMaxLength(int[] nums) {
        Map<Integer, TreeSet<Integer>> countMap = new HashMap<>();
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            count += (nums[i] - 0.5) * 2;
            if (!countMap.containsKey(count)) {
                countMap.put(count, new TreeSet<>());
            }
            countMap.get(count).add(i);
        }
        int maxLength = 0;
        for (TreeSet<Integer> countSet : countMap.values()) {
            maxLength = Math.max(maxLength, countSet.last() - countSet.first());
        }
        if (countMap.containsKey(0)) {
            maxLength = Math.max(maxLength, countMap.get(0).last() + 1);
        }
        return maxLength;
    }
}