class Solution {
    public int maxDistToClosest(int[] seats) {
        int distance = 0;
        int index = 0;
        while (index < seats.length && seats[index] == 0) {
            index++;
        }
        distance = Math.max(distance, index);
        index = seats.length - 1;
        while (index >= 0 && seats[index] == 0) {
            index--;
        }
        distance = Math.max(distance, seats.length - 1 - index);
        int count = 0;
        for (int i = 0; i < seats.length; i++) {
            if (seats[i] == 0) {
                count++;
            } else {
                distance = Math.max(distance, (count + 1) / 2);
                count = 0;
            }
        }
        return distance;
    }
}