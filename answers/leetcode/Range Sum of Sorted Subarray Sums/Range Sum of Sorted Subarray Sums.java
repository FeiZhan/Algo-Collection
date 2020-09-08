class Solution {

    private static final int MOD = 1_000_000_007;

    private class Pair {
        public int first;
        public int second;

        public Pair(int f, int s) {
            this.first = f;
            this.second = s;
        }
    }

    public int rangeSum(int[] nums, int n, int left, int right) {
        PriorityQueue<Pair> nextQueue = new PriorityQueue<>((p1, p2) -> p1.first - p2.first);
        for (int i = 0; i < nums.length; i++) {
            Pair pair = new Pair(nums[i], i + 1);
            nextQueue.add(pair);
        }
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        while (queue.size() < right && !nextQueue.isEmpty()) {
            Pair pair = nextQueue.poll();
            int number = pair.first;
            int index = pair.second;
            queue.add(number);
            if (index < nums.length) {
                Pair nextPair = new Pair(number + nums[index], index + 1);
                nextQueue.add(nextPair);
            }
        }
        for (int i = 1; i < left; i++) {
            queue.remove();
        }
        int sum = 0;
        while (!queue.isEmpty()) {
            sum = (sum + queue.poll()) % MOD;
        }
        return sum;
    }
}