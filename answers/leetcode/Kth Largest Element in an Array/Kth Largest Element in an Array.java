class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> largest = new PriorityQueue<>(k);
        for (int num : nums) {
            largest.add(num);
            if (largest.size() > k) {
                largest.poll();
            }
        }
        return largest.poll();
    }
}