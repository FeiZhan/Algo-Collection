class MyCircularDeque {

    private int head = -1;
    private int tail = -1;
    private List<Integer> list = new ArrayList<>();

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        for (int i = 0; i < k; i++) {
            this.list.add(-1);
        }
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if (this.isFull()) {
            return false;
        } else if (this.isEmpty()) {
            this.head = 0;
            this.tail = 0;
        } else {
            this.head = this.minusOne(this.head);
        }
        this.list.set(this.head, value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if (this.isFull()) {
            return false;
        } else if (this.isEmpty()) {
            this.head = 0;
            this.tail = 0;
        } else {
            this.tail = this.plusOne(this.tail);
        }
        this.list.set(this.tail, value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if (this.isEmpty()) {
            return false;
        }
        if (this.head == this.tail) {
            this.head = -1;
            this.tail = -1;
        } else {
            this.head = this.plusOne(this.head);
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if (this.isEmpty()) {
            return false;
        }
        if (this.head == this.tail) {
            this.head = -1;
            this.tail = -1;
        } else {
            this.tail = this.minusOne(this.tail);
        }
        return true;
        
    }
    
    /** Get the front item from the deque. */
    public int getFront() {
        return this.isEmpty() ? -1 : this.list.get(this.head);
    }
    
    /** Get the last item from the deque. */
    public int getRear() {
        return this.isEmpty() ? -1 : this.list.get(this.tail);
    }
    
    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return this.head == -1;
    }
    
    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return this.head == this.plusOne(this.tail);
    }

    private int minusOne(int value) {
        return (value - 1 + this.list.size()) % this.list.size();
    }

    private int plusOne(int value) {
        return (value + 1) % this.list.size();
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */