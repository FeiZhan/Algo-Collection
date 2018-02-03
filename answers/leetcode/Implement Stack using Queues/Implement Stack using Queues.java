class MyStack {

    private Queue<Integer> inQueue;
    private Queue<Integer> outQueue;

    /** Initialize your data structure here. */
    public MyStack() {
        this.inQueue = new PriorityQueue<Integer>();
        this.outQueue = new PriorityQueue<Integer>();
    }

    /** Push element x onto stack. */
    public void push(int x) {
        this.inQueue.add(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        this.moveToOutQueue();
        return this.inQueue.remove();
    }

    /** Get the top element. */
    public int top() {
        this.moveToOutQueue();
        return this.inQueue.peek();
    }

    /** Returns whether the stack is empty. */
    public boolean empty() {
        return this.inQueue.isEmpty() && this.outQueue.isEmpty();
    }

    private void moveToOutQueue() {
        if (this.inQueue.isEmpty()) {
            this.inQueue = new PriorityQueue<Integer>(this.outQueue);
            this.outQueue.clear();
        }
        while (this.inQueue.size() > 1) {
            this.outQueue.add(this.inQueue.remove());
        }
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */