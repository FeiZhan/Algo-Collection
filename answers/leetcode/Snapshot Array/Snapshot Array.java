class SnapshotArray {

    private int count = 0;
    private List<TreeMap<Integer, Integer>> snapshots;

    public SnapshotArray(int length) {
        this.snapshots = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            TreeMap<Integer, Integer> map = new TreeMap<>();
            map.put(0, 0);
            this.snapshots.add(map);
        }
    }

    public void set(int index, int val) {
        TreeMap<Integer, Integer> map = this.snapshots.get(index);
        map.put(this.count, val);
    }

    public int snap() {
        return this.count++;
    }

    public int get(int index, int snap_id) {
        return this.snapshots.get(index).floorEntry(snap_id).getValue();
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */