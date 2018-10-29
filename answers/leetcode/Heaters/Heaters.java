class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int radius = 0;
        int i = 0;
        for (int house : houses) {
            while (i + 1 < heaters.length && house - heaters[i] >= heaters[i + 1] - house) {
                i++;
            }
            radius = Math.max(radius, Math.abs(heaters[i] - house));
        }
        return radius;
    }
}