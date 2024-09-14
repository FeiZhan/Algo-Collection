class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        return Math.max(run(red, blue), run(blue, red));
    }

    private int run(int color0, int color1) {
        int level = 0;
        while (color0 >= 0 && color1 >= 0) {
            level++;
            if (level % 2 == 0) {
                color0 -= level;
            } else {
                color1 -= level;
            }
        }

        return level - 1;
    }
}