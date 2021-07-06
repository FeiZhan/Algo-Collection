class LRUCache {

    private int capacity;
    private CacheDeque deque;
    private Map<Integer, CacheDequeNode> nodeMap;
    private Map<Integer, Integer> valueMap;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.deque = new CacheDeque();
        this.nodeMap = new HashMap<>();
        this.valueMap = new HashMap<>();
    }

    public int get(int key) {
        if (!this.valueMap.containsKey(key)) {
            return -1;
        }

        int value = this.valueMap.get(key);
        this.put(key, value);
        return value;
    }

    public void put(int key, int value) {
        if (this.nodeMap.containsKey(key)) {
            CacheDequeNode node = this.nodeMap.get(key);
            deque.remove(node);
        }

        this.deque.enqueue(key);
        this.nodeMap.put(key, this.deque.head);
        this.valueMap.put(key, value);

        //System.out.println("head " + key + " " + this.deque.head.key + " " + this.deque.tail.key);

        if (this.nodeMap.size() > this.capacity) {
            int tailKey = this.deque.tail.key;
            deque.dequeue();
            nodeMap.remove(tailKey);
            valueMap.remove(tailKey);
        }
    }

    private class CacheDequeNode {

        public int key;
        public CacheDequeNode left;
        public CacheDequeNode right;

        public CacheDequeNode(int key) {
            this.key = key;
            this.left = null;
            this.right = null;
        }
    }

    private class CacheDeque {

        public CacheDequeNode head = null;
        public CacheDequeNode tail = null;

        public CacheDeque() {
        }

        public void remove(CacheDequeNode node) {
            if (node == null) {
                return;
            }

            if (this.head == node) {
                this.head = node.right;
            }
            if (this.tail == node) {
                this.tail =  node.left;
            }
            if (node.left != null) {
                node.left.right = node.right;
            }
            if (node.right != null) {
                node.right.left = node.left;
            }
        }

        public void enqueue(int key) {
            CacheDequeNode node = new CacheDequeNode(key);
            node.right = this.head;
            if (this.head != null) {
                this.head.left = node;
            }
            this.head = node;

            if (this.tail == null) {
                this.tail = node;
            }
        }

        public void dequeue() {
            this.remove(this.tail);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */