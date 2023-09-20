class Solution {
    public int countPairs(List<Integer> nums, int target) {
        int counts = 0;
        Collections.sort(nums);

        for (int i = 0; i < nums.size(); i++) {
            int subTarget = target - nums.get(i);
            int left = i + 1;
            int right = nums.size() - 1;
            int middle = 0;

            while (left <= right) {
                middle = (left + right) / 2;
                if (nums.get(middle) >= subTarget) {
                    right = middle - 1;
                } else if (middle + 1 == nums.size()) {
                    counts += middle - i;
                    break;
                } else if (nums.get(middle + 1) < subTarget) {
                    left = middle + 1;
                } else {
                    counts += middle - i;
                    break;
                }
            }
        }

        return counts;
    }
}