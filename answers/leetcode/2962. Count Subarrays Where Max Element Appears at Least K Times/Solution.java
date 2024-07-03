class Solution {
    public long countSubarrays(int[] nums, int k) {
        int max = 0;
        for (int number : nums) {
            max = Math.max(max, number);
        }

        long result = 0l;
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == max) {
                queue.add(i);
                while (queue.size() > k) {
                    queue.poll();
                }
            }
            if (queue.size() == k) {
                result += (long)(queue.peek()) + 1l;
            }
        }

        return result;
    }
}