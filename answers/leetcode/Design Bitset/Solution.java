class Bitset {

    private Set<Integer> ones = new HashSet<>();
    private Set<Integer> zeros = new HashSet<>();

    public Bitset(int size) {
        for (int i = 0; i < size; i++) {
            zeros.add(i);
        }
    }

    public void fix(int idx) {
        this.ones.add(idx);
        this.zeros.remove(idx);
    }

    public void unfix(int idx) {
        this.ones.remove(idx);
        this.zeros.add(idx);
    }

    public void flip() {
        Set<Integer> temp = this.ones;
        this.ones = this.zeros;
        this.zeros = temp;
    }

    public boolean all() {
        return this.zeros.isEmpty();
    }

    public boolean one() {
        return !this.ones.isEmpty();
    }

    public int count() {
        return this.ones.size();
    }

    public String toString() {
        int index = 0;
        StringBuilder sb = new StringBuilder();
        while (this.ones.contains(index) || this.zeros.contains(index)) {
            sb.append(this.ones.contains(index) ? '1' : '0');
            index++;
        }

        return sb.toString();
    }
}

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset obj = new Bitset(size);
 * obj.fix(idx);
 * obj.unfix(idx);
 * obj.flip();
 * boolean param_4 = obj.all();
 * boolean param_5 = obj.one();
 * int param_6 = obj.count();
 * String param_7 = obj.toString();
 */
//Runtime: 187 ms, faster than 26.35% of Java online submissions for Design Bitset.
//Memory Usage: 175.4 MB, less than 5.02% of Java online submissions for Design Bitset.
