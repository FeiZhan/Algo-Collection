class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> result = new LinkedList<>();
        for (int i = 0; i < l.length; i++) {
            List<Integer> subarray = new LinkedList<>();
            for (int j = l[i]; j <= r[i]; j++) {
                subarray.add(nums[j]);
            }
            Collections.sort(subarray);
            boolean flag = true;
            for (int j = 2; j < subarray.size(); j++) {
                if (subarray.get(j - 1) - subarray.get(j - 2) != subarray.get(j) - subarray.get(j - 1)) {
                    flag = false;
                    break;
                }
            }
            result.add(flag);
        }
        return result;
    }
}