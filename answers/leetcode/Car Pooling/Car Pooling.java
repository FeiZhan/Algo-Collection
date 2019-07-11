import java.util.SortedMap;

class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        SortedMap<Integer, Integer> passengers = new TreeMap<>();
        for (int[] trip : trips) {
            passengers.put(trip[1], passengers.getOrDefault(trip[1], 0) + trip[0]);
            passengers.put(trip[2], passengers.getOrDefault(trip[2], 0) - trip[0]);
        }
        int car = 0;
        for (int passenger : passengers.values()) {
            car += passenger;
            if (car > capacity) {
                return false;
            }
        }
        return true;
    }
}

