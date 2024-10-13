class LFUCache {

    private int capacity = 0;
    private int minCount = 1;
    private Map<Integer, Integer> keyMap = new HashMap<>();
    private Map<Integer, Integer> keyCountMap = new HashMap<>();
    private Map<Integer, Set<Integer>> countMap = new HashMap<>();

    public LFUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public int get(int key) {
        if (!keyMap.containsKey(key)) {
            return -1;
        }

        incrementCount(key);
        return keyMap.get(key);
    }
    
    public void put(int key, int value) {
        if (!keyMap.containsKey(key) && keyMap.size() >= capacity) {
            Set<Integer> keySet = countMap.get(minCount);
            int minKey = keySet.iterator().next();
            removeCount(minKey);
            keyMap.remove(minKey);
        }

        incrementCount(key);
        keyMap.put(key, value);
    }

    private void removeCount(int key) {
        if (!keyMap.containsKey(key)) {
            return;
        }
        if (!keyCountMap.containsKey(key)){
            return;
        }

        int count = keyCountMap.get(key);
        keyCountMap.remove(key);
        Set<Integer> keySet = countMap.get(count);
        keySet.remove(key);
        if (keySet.isEmpty()) {
            countMap.remove(count);
            if (minCount == count) {
                minCount++;
            }
        }
    }

    private void incrementCount(int key) {
        int count = keyCountMap.getOrDefault(key, 0) + 1;
        removeCount(key);
        keyCountMap.put(key, count);
        Set<Integer> keySet = countMap.getOrDefault(count, new LinkedHashSet<>());
        keySet.add(key);
        countMap.put(count, keySet);
        minCount = Math.min(minCount, count);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */