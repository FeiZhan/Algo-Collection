class Solution {
    public int[] sortEvenOdd(int[] nums) {
        PriorityQueue<Integer> even = new PriorityQueue<>();
        PriorityQueue<Integer> odd = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < nums.length; i++) {
            if (i % 2 == 0) {
                even.add(nums[i]);
            } else {
                odd.add(nums[i]);
            }
        }

        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            result[i] = i % 2 == 0 ? even.poll() : odd.poll();
        }

        return result;
    }
}
//Runtime: 6 ms, faster than 62.31% of Java online submissions for Sort Even and Odd Indices Independently.
//Memory Usage: 45.2 MB, less than 31.29% of Java online submissions for Sort Even and Odd Indices Independently.
