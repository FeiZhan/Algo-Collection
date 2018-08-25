class MedianFinder {
    
    private Queue<Integer> largeQueue;
    private Queue<Integer> smallQueue;

    /** initialize your data structure here. */
    public MedianFinder() {
        this.largeQueue = new PriorityQueue<>();
        this.smallQueue = new PriorityQueue<>(Collections.reverseOrder());
    }
    
    public void addNum(int num) {
        this.largeQueue.add(num);
        this.smallQueue.add(this.largeQueue.poll());
        while (this.smallQueue.size() > this.largeQueue.size() + 1) {
            this.largeQueue.add(this.smallQueue.poll());
        }
    }
    
    public double findMedian() {
        if (this.smallQueue.size() == this.largeQueue.size()) {
            return (this.smallQueue.peek() + this.largeQueue.peek()) / 2.0;
        } else {
            return this.smallQueue.peek();
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */