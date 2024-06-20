class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        int count = 0;
        Map<Integer, Integer> occurrences = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == x) {
                count++;
                occurrences.put(count, i);
            }
        }

        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            result[i] = occurrences.getOrDefault(queries[i], -1);
        }

        return result;
    }
}