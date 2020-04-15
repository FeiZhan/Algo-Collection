import java.util.SortedMap;

class CustomStack {

    private int maxSize = 0;
    private SortedMap<Integer, Integer> increments = new TreeMap<>();
    private Stack<Integer> stack = new Stack<>();

    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
    }

    public void push(int x) {
        if (this.stack.size() < this.maxSize) {
            this.stack.push(x);
        }
    }

    public int pop() {
        if (this.stack.isEmpty()) {
            return -1;
        }
        int size = this.stack.size();
        SortedMap<Integer, Integer> tail = this.increments.tailMap(size);
        int sum = 0;
        for (int key : tail.keySet()) {
            sum += tail.get(key);
            this.increments.remove(key);
        }
        this.increments.put(size - 1, this.increments.getOrDefault(size - 1, 0) + sum);
        return this.stack.pop() + sum;
    }

    public void increment(int k, int val) {
        int size = Math.min(k, this.stack.size());
        this.increments.put(size, this.increments.getOrDefault(size, 0) + val);
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */