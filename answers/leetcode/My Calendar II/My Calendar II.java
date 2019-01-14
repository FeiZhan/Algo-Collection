class MyCalendarTwo {

    private TreeMap<Integer, Integer> booked = new TreeMap<>();

    public MyCalendarTwo() {
    }

    public boolean book(int start, int end) {
        this.booked.put(start, this.booked.getOrDefault(start, 0) + 1);
        this.booked.put(end, this.booked.getOrDefault(end, 0) - 1);
        int count = 0;
        for (int value : this.booked.values()) {
            count += value;
            if (count >= 3) {
                this.booked.put(start, this.booked.getOrDefault(start, 0) - 1);
                this.booked.put(end, this.booked.getOrDefault(end, 0) + 1);
                return false;
            }
        }
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */