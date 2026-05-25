class MyHashSet {

    private static final int SIZE = 1000001;

    private boolean[] array = new boolean[SIZE];

    /** Initialize your data structure here. */
    public MyHashSet() {
    }
    
    public void add(int key) {
        this.array[key] = true;
    }
    
    public void remove(int key) {
        this.array[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return this.array[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */