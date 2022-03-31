class Solution {
    public int halveArray(int[] nums) {
        double sum = 0.0;
        PriorityQueue<Double> queue = new PriorityQueue<>(Collections.reverseOrder());
        for (int number : nums) {
            sum += number;
            queue.add((double) number);
        }

        int result = 0;
        double half = sum / 2.0;

        while (sum > half) {
            double number = queue.poll() / 2.0;
            sum -= number;
            queue.add(number);
            result++;
        }

        return result;
    }
}
//Runtime: 316 ms, faster than 65.62% of Java online submissions for Minimum Operations to Halve Array Sum.
//Memory Usage: 108.9 MB, less than 70.96% of Java online submissions for Minimum Operations to Halve Array Sum.
