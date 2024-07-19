class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int water = capacity;
        int result = 0;
        for (int i = 0; i < plants.length; i++) {
            if (water >= plants[i]) {
                result++;
                water -= plants[i];
            } else {
                result += i + i + 1;
                water = capacity - plants[i];
            }
        }

        return result;
    }
}