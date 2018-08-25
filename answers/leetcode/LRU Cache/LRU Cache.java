class LRUCache {
    
    private int capacity;
    private LinkedHashMap<Integer, Integer> cacheMap;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.cacheMap = new LinkedHashMap<Integer, Integer>(capacity, 1f, true) {
            
            protected boolean removeEldestEntry(Map.Entry eldest) {
                return this.size() > capacity;
            }
        };
    }
    
    public int get(int key) {
        return this.cacheMap.getOrDefault(key, -1);
    }
    
    public void put(int key, int value) {
        this.cacheMap.put(key, value);
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */