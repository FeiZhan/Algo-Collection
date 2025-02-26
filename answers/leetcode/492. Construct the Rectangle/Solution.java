class Solution {
    public int[] constructRectangle(int area) {
        int sqrt = (int) Math.sqrt((double) area);
        while (area % sqrt != 0) {
            sqrt -= 1;
        }
        int[] result = new int[2];
        result[1] = sqrt;
        result[0] = area / result[1];
        return result;
    }
}