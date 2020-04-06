class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int[][] cars = new int[position.length][2];
        for (int i = 0; i < position.length; i++) {
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }
        Arrays.sort(cars, (int[] car0, int[] car1) -> car1[0] - car0[0]);
        double[] arrivalTimes = new double[cars.length];
        int count = 0;
        for (int i = 0; i < cars.length; i++) {
            double arrivalTime = (double)(target - cars[i][0]) / cars[i][1];
            if (i > 0 && arrivalTime <= arrivalTimes[i - 1]) {
                arrivalTimes[i] = arrivalTimes[i - 1];
            } else {
                arrivalTimes[i] = arrivalTime;
                count++;
            }
        }
        return count;
    }
}