class Solution {
    public int heightChecker(int[] heights) {
        int[] copied = Arrays.copyOf(heights, heights.length);
        Arrays.sort(copied);
        int count = 0;
        for (int i = 0; i < heights.length; i++) {
            count += heights[i] == copied[i] ? 0 : 1;
        }
        return count;
    }
}