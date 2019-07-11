class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0 || k == 0) {
            return new int[0];
        }

        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i + 1 < k; i++) {
            queue.add(nums[i]);
        }
        int[] result = new int[nums.length - k + 1];
        for (int i = k - 1; i < nums.length; i++) {
            if (i - k >= 0) {
                queue.remove(nums[i - k]);
            }
            if (i >= 0) {
                queue.add(nums[i]);
            }
            if (i - k + 1 >= 0 && !queue.isEmpty()) {
                result[i - k + 1] = queue.peek();
            }
        }
        return result;
    }
}