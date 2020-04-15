class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int num : nums) {
            queue.add(num);
        }
        while (!queue.isEmpty()) {
            int first = queue.poll();
            for (int i = 1; i < k; i++) {
                if (!queue.contains(first + i)) {
                    return false;
                }
                queue.remove(first + i);
            }
        }
        return true;
    }
}