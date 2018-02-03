class MyQueue {

    private Stack<Integer> inStack;
    private Stack<Integer> outStack;

    /** Initialize your data structure here. */
    public MyQueue() {
        this.inStack = new Stack<Integer>();
        this.outStack = new Stack<Integer>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        this.inStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (this.outStack.empty()) {
            this.moveToOutStack();
        }
        return this.outStack.pop();
    }

    /** Get the front element. */
    public int peek() {
        if (this.outStack.empty()) {
            this.moveToOutStack();
        }
        return this.outStack.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return this.inStack.empty() && this.outStack.empty();
    }

    private void moveToOutStack() {
        while (!this.inStack.empty()) {
            this.outStack.push(this.inStack.pop());
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */