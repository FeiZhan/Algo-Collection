import java.util.SortedMap;

class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        SortedMap<Integer, Integer> seats = new TreeMap<>();
        for (int[] booking : bookings) {
            seats.put(booking[0], seats.getOrDefault(booking[0], 0) + booking[2]);
            seats.put(booking[1] + 1, seats.getOrDefault(booking[1] + 1, 0) - booking[2]);
        }
        int sum = 0;
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            sum += seats.getOrDefault(i + 1, 0);
            result[i] = sum;
        }
        return result;
    }
}