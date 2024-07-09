class LRUCache {

    int capacity = 0;
    private DoubleLinkedListNode head = null;
    private DoubleLinkedListNode tail = null;
    private Map<Integer, Integer> valueMap = new HashMap<>();
    private Map<Integer, DoubleLinkedListNode> nodeMap = new HashMap<>();

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head = new DoubleLinkedListNode(-1);
        tail = new DoubleLinkedListNode(-1);
        head.next = tail;
        tail.previous = head;
    }

    public int get(int key) {
        if (valueMap.containsKey(key)) {
            enqueue(key);
        }
        return valueMap.getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        valueMap.put(key, value);
        enqueue(key);
    }

    private void enqueue(int value) {
        DoubleLinkedListNode node = null;
        if (nodeMap.containsKey(value)) {
            node = nodeMap.get(value);
            node.previous.next = node.next;
            node.next.previous = node.previous;
        } else {
            node = new DoubleLinkedListNode(value);
            nodeMap.put(value, node);
        }
        node.previous = tail.previous;
        tail.previous.next = node;
        node.next = tail;
        tail.previous = node;

        while (valueMap.size() > capacity) {
            DoubleLinkedListNode least = head.next;
            if (least == null || least == tail) {
                break;
            }
            head.next = least.next;
            least.next.previous = head;
            valueMap.remove(least.value);
            nodeMap.remove(least.value);
        }
    }

    private class DoubleLinkedListNode {

        public int value = 0;
        public DoubleLinkedListNode previous = null;
        public DoubleLinkedListNode next = null;

        public DoubleLinkedListNode(int value) {
            this.value = value;
        }
    }

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */