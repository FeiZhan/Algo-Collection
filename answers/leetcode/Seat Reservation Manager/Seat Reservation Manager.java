class SeatManager {

    private PriorityQueue<Integer> queue = new PriorityQueue<>();

    public SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            this.queue.add(i);
        }
    }

    public int reserve() {
        return this.queue.poll();
    }

    public void unreserve(int seatNumber) {
        this.queue.add(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */