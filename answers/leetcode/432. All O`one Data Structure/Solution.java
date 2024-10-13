class AllOne {

    private Map<String, Integer> keyMap = new HashMap<>();
    private Map<Integer, Node> countMap = new HashMap<>();
    private Node head = new Node();
    private Node tail = new Node();

    public AllOne() {
        head.next = tail;
        tail.previous = head;
    }
    
    public void inc(String key) {
        Node previousNode = head;
        if (keyMap.containsKey(key)) {
            int count = keyMap.get(key);
            previousNode = countMap.get(count);
            previousNode.keySet.remove(key);
            if (previousNode.keySet.isEmpty()) {
                previousNode.previous.next = previousNode.next;
                previousNode.next.previous = previousNode.previous;
                previousNode = previousNode.previous;
                countMap.remove(count);
            }
        }

        int count = keyMap.getOrDefault(key, 0) + 1;
        keyMap.put(key, count);
        Node node = countMap.getOrDefault(count, new Node());
        node.keySet.add(key);
        if (!countMap.containsKey(count)) {
            node.previous = previousNode;
            node.next = previousNode.next;
            previousNode.next.previous = node;
            previousNode.next = node;
            countMap.put(count, node);
        }
    }
    
    public void dec(String key) {
        if (!keyMap.containsKey(key)) {
            return;
        }

        int count = keyMap.get(key);
        Node nextNode = countMap.get(count);
        nextNode.keySet.remove(key);
        if (nextNode.keySet.isEmpty()) {
            nextNode.previous.next = nextNode.next;
            nextNode.next.previous = nextNode.previous;
            nextNode = nextNode.next;
            countMap.remove(count);
        }
        keyMap.remove(key);
        count--;
        if (count <= 0) {
            return;
        }

        keyMap.put(key, count);
        Node node = countMap.getOrDefault(count, new Node());
        node.keySet.add(key);
        if (!countMap.containsKey(count)) {
            node.previous = nextNode.previous;
            node.next = nextNode;
            nextNode.previous.next = node;
            nextNode.previous = node;
            countMap.put(count, node);
        }
    }
    
    public String getMaxKey() {
        Set<String> keySet = tail.previous.keySet;
        return keySet.isEmpty() ? "" : keySet.iterator().next();
    }
    
    public String getMinKey() {
        Set<String> keySet = head.next.keySet;
        return keySet.isEmpty() ? "" : keySet.iterator().next();
    }

    private class Node {
        public Set<String> keySet = new HashSet<>();
        public Node previous = null;
        public Node next = null;
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */