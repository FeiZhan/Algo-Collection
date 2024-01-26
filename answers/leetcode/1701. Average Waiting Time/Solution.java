class Solution {
    public double averageWaitingTime(int[][] customers) {
        int current = 0;
        double sum = 0.;
        for (int[] customer : customers) {
            current = Math.max(current, customer[0]) + customer[1];
            sum += (double)(current - customer[0]);
        }

        return sum / (double) customers.length;
    }
}