class ParkingSystem {

    private int[] counts = new int[3];

    public ParkingSystem(int big, int medium, int small) {
        this.counts[0] = big;
        this.counts[1] = medium;
        this.counts[2] = small;
    }

    public boolean addCar(int carType) {
        if (this.counts[carType - 1] > 0) {
            this.counts[carType - 1]--;
            return true;
        } else {
            return false;
        }
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */