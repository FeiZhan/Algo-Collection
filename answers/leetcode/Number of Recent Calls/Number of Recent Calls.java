class RecentCounter {

    private Queue<Integer> queue = new LinkedList<>();

    public RecentCounter() {
    }
    
    public int ping(int t) {
        this.queue.add(t);
        while (!this.queue.isEmpty() && this.queue.peek() < t - 3000) {
            this.queue.poll();
        }
        return this.queue.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */