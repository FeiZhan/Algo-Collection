class KthLargest {

    private int size;
    private PriorityQueue<Integer> queue = new PriorityQueue<>();

    public KthLargest(int k, int[] nums) {
        this.size = k;
        for (int num : nums) {
            this.queue.add(num);
            if (this.queue.size() > k) {
                this.queue.poll();
            }
        }
    }
    
    public int add(int val) {
        this.queue.add(val);
        if (this.queue.size() > this.size) {
            this.queue.poll();
        }
        return this.queue.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */