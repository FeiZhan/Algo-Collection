class Solution {
    public int findShortestSubArray(int[] nums) {
        int degree = 0;
        Map<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>();
        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                List<Integer> numList = new ArrayList<Integer>();
                numList.add(0);
                numList.add(i);
                numList.add(i);
                map.put(nums[i], numList);
            }
            List<Integer> numList = map.get(nums[i]);
            numList.set(0, numList.get(0) + 1);
            numList.set(2, i);
            degree = Math.max(degree, numList.get(0));
        }
        int shortest = Integer.MAX_VALUE;
        for (List<Integer> numList : map.values()) {
            if (numList.get(0) == degree) {
                shortest = Math.min(shortest, numList.get(2) - numList.get(1) + 1);
            }
        }
        return shortest;
    }
}