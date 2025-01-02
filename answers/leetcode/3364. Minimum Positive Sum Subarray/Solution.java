class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int sum = 0;
        List<Integer> sums = new ArrayList<>();
        sums.add(0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.get(i);
            sums.add(sum);
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = l - 1; j < r && i + j < nums.size(); j++) {
                int diff = sums.get(i + j + 1) - sums.get(i);
                if (diff > 0) {
                    result = Math.min(result, diff);
                }
                //System.out.println(i + " " + (i + j) + ": " + diff + " " + result);
            }
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}