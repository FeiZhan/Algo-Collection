class OrderedStream {

    private int index = 1;
    private Map<Integer, String> values = new HashMap<>();

    public OrderedStream(int n) {
    }

    public List<String> insert(int idKey, String value) {
        this.values.put(idKey, value);
        List<String> result = new LinkedList<>();

        while (this.values.containsKey(this.index)) {
            result.add(this.values.get(this.index));
            this.index++;
        }

        return result;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */
//Runtime: 163 ms, faster than 35.92% of Java online submissions for Design an Ordered Stream.
//Memory Usage: 89.2 MB, less than 46.78% of Java online submissions for Design an Ordered Stream.
