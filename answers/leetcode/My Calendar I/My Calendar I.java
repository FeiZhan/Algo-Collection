import java.util.SortedMap;

class MyCalendar {

    private TreeMap<Integer, Integer> booked = new TreeMap<>();

    public MyCalendar() {
    }

    public boolean book(int start, int end) {
        Integer lowerKey = this.booked.lowerKey(start);
        if (lowerKey != null) {
            int lowerValue = this.booked.get(lowerKey);
            if (lowerValue > start) {
                return false;
            }
        }
        SortedMap<Integer, Integer> subMap = this.booked.subMap(start, end);
        if (subMap.size() > 0) {
            return false;
        }
        this.booked.put(start, end);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */