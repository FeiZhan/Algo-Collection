class RandomizedSet {
    
    private List<Integer> valueList;
    private Map<Integer, Integer> valueMap;
    private Random random;

    /** Initialize your data structure here. */
    public RandomizedSet() {
        this.valueList = new ArrayList<>();
        this.valueMap = new HashMap<>();
        this.random = new Random();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (this.valueMap.containsKey(val)) {
            return false;
        } else {
            this.valueList.add(val);
            this.valueMap.put(val, this.valueList.size() - 1);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (this.valueMap.containsKey(val)) {
            int index = this.valueMap.get(val);
            int lastIndex = this.valueList.size() - 1;
            if (index < lastIndex) {
                int last = this.valueList.get(lastIndex);
                this.valueList.set(index, last);
                this.valueMap.put(last, index);
            }
            this.valueList.remove(lastIndex);
            this.valueMap.remove(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        int index = this.random.nextInt(this.valueList.size());
        return this.valueList.get(index);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */