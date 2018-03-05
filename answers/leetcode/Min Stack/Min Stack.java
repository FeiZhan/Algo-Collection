class MinStack {

    private long min;
    private Stack<Long> stack;

    /** initialize your data structure here. */
    public MinStack() {
        this.min = 0;
        this.stack = new Stack<Long>();
    }

    public void push(int x) {
        long longX = (long) x;
        long newValue = 0;
        if (this.stack.isEmpty()) {
            newValue = 0;
            this.min = longX;
        } else if (this.min > longX) {
            newValue = longX - this.min;
            this.min = longX;
        } else {
            newValue = longX - this.min;
        }
        this.stack.push(newValue);
    }

    public void pop() {
        if (!this.stack.isEmpty()) {
            long top = this.stack.pop();
            if (top < 0) {
                this.min -= top;
            }
        }
    }

    public int top() {
        long top = this.stack.peek();
        if (top >= 0) {
            return (int) (top + this.min);
        } else {
            return (int) this.min;
        }
    }

    public int getMin() {
        return (int) this.min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */