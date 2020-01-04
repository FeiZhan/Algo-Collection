class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int count = 1;
        int id = 0;
        int[] result = new int[num_people];
        while (candies > 0) {
            result[id] += Math.min(count, candies);
            candies -= count;
            count++;
            id = (id + 1) % num_people;
        }
        return result;
    }
}