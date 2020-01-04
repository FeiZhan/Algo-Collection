class MyCircularQueue {

    private int head = -1;
    private int tail = -1;
    private List<Integer> list = new ArrayList<>();

    /** Initialize your data structure here. Set the size of the queue to be k. */
    public MyCircularQueue(int k) {
        for (int i = 0; i < k; i++) {
            this.list.add(0);
        }
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    public boolean enQueue(int value) {
        if (this.isFull()) {
            return false;
        }
        this.tail = this.plusOne(this.tail);
        this.list.set(this.tail, value);
        if (this.head == -1) {
            this.head = this.tail;
        }
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if (this.isEmpty()) {
            return false;
        }
        if (this.head == this.tail) {
            this.head = -1;
            this.tail = -1;
        } else {
            this.head = this.plusOne(head);
        }
        return true;
    }
    
    /** Get the front item from the queue. */
    public int Front() {
        return this.isEmpty() ? -1 : this.list.get(this.head);
    }
    
    /** Get the last item from the queue. */
    public int Rear() {
        return this.isEmpty() ? -1 : this.list.get(this.tail);
    }
    
    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return this.head == -1;
    }
    
    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return this.plusOne(this.tail) == this.head;
    }

    private int plusOne(int value) {
        return (value + 1) % this.list.size();
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */