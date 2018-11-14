class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int length = nums.length;
        int[] count = new int[length];
        int[] pre = new int[length];
        int max = 0;
        int index = -1;

        for (int i = 0; i < length; i++) {
            count[i] = 1;
            pre[i] = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && count[i] < count[j] + 1) {
                    count[i] = count[j] + 1;
                    pre[i] = j;
                }
            }
            if (count[i] > max) {
                max = count[i];
                index = i;
            }
        }
        List<Integer> result = new LinkedList<>();
        while (index != -1) {
            result.add(nums[index]);
            index = pre[index];
        }
        return result;
    }
}