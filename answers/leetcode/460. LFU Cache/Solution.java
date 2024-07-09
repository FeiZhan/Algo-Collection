import java.util.SortedMap;

class LFUCache {

    private int capacity = 0;
    private Map<Integer, Integer> valueMap = new HashMap<>();
    private Map<Integer, Integer> countMap = new HashMap<>();
    private SortedMap<Integer, Set<Integer>> counterMap = new TreeMap<>();

    public LFUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        increment(key);
        return valueMap.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        if (!valueMap.containsKey(key) && valueMap.size() >= capacity) {
            int leastCount = counterMap.firstKey();
            Set<Integer> set = counterMap.get(leastCount);
            int leastKey = set.iterator().next();
            valueMap.remove(leastKey);
            countMap.remove(leastKey);
            set.remove(leastKey);
            if (set.isEmpty()) {
                counterMap.remove(leastCount);
            }
        }

        valueMap.put(key, value);
        increment(key);
    }

    private void increment(int key) {
        if (!valueMap.containsKey(key)) {
            return;
        }

        int count = countMap.getOrDefault(key, 0);
        if (count > 0) {
            Set<Integer> set = counterMap.get(count);
            set.remove(key);
            if (set.isEmpty()) {
                counterMap.remove(count);
            }
        }
        count++;
        countMap.put(key, count);
        Set<Integer> set = counterMap.getOrDefault(count, new LinkedHashSet<>());
        set.add(key);
        counterMap.put(count, set);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */